
#ifndef Extensions_Sqlite3RowTell_h
#define Extensions_Sqlite3RowTell_h


// Library includes

// Project includes
#include "Defines.h"

// Forward declarations

// Namespace declarations
using namespace Slang;


namespace Sqlite3 {


class Sqlite3RowTell : public Extensions::ExtensionMethod
{
public:
    Sqlite3RowTell()
	: ExtensionMethod(0, "sqlite3_row_tell", Designtime::Int32Type::TYPENAME)
	{
		ParameterList params;
		params.push_back(Parameter::CreateDesigntime("result", Designtime::Int32Type::TYPENAME));

		setSignature(params);
	}

public:
	Runtime::ControlFlow::E execute( const ParameterList& params, Runtime::Object* result )
	{
		ParameterList list = mergeParameters(params);

		ParameterList::const_iterator it = list.begin();

		auto param_result = (*it++).value().toInt();

		int rowIdx = 0;

		if ( param_result > 0 && param_result < (int)mResults.size() ) {
			rowIdx = (int)mResults[param_result].rowTell();
		}

		*result = Runtime::Int32Type( rowIdx );

		return Runtime::ControlFlow::Normal;
	}
};


}


#endif
