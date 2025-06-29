
#ifndef Extensions_Sqlite3Exec_h
#define Extensions_Sqlite3Exec_h


// Library includes

// Project includes
#include "Defines.h"
#include "Types.h"

// Forward declarations

// Namespace declarations
using namespace Slang;


namespace Sqlite3 {


static int callback(void* /*data*/, int argc, char** argv, char** azColName)
{
    Sqlite3Result& result = mResults[mResults.size() - 1];

    Sqlite3Row row;
    for ( int idx = 0; idx < argc; ++idx ) {
        row.push( std::string(azColName[idx]), std::string(argv[idx]) );
    }

    result.pushRow( row );

    return 0;
}


class Sqlite3Exec : public Extensions::ExtensionMethod
{
public:
    Sqlite3Exec()
	: ExtensionMethod(0, "sqlite3_exec", Designtime::Int32Type::TYPENAME)
	{
		ParameterList params;
		params.push_back(Parameter::CreateDesigntime("handle", Designtime::Int32Type::TYPENAME));
        params.push_back(Parameter::CreateDesigntime("query", Designtime::StringType::TYPENAME));

		setSignature(params);
	}

public:
	Runtime::ControlFlow::E execute( const ParameterList& params, Runtime::Object* result )
	{
		ParameterList list = mergeParameters(params);

		ParameterList::const_iterator it = list.begin();

		auto param_handle = (*it++).value().toInt();
		auto param_sql = (*it++).value().toStdString();

		int result_handle = 0;

		if ( param_handle > 0 && param_handle < (int)mConnections.size() ) {
			// initialize result
			result_handle = mResults.size();
			mResults[result_handle] = Sqlite3Result();

			// execute query
			int error = sqlite3_exec(mConnections[param_handle], param_sql.c_str(), callback, NULL, NULL);
			if ( error ) {
				// if an error occurs we return 0, which indicates an invalid result handle
				result_handle = 0;
			}
		}

		*result = Runtime::Int32Type( result_handle );

		return Runtime::ControlFlow::Normal;
	}
};


}


#endif
