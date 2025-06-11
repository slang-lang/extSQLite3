
#ifndef Extensions_Sqlite3RowSeek_h
#define Extensions_Sqlite3RowSeek_h


// Library includes

// Project includes
#include "Defines.h"

// Forward declarations

// Namespace declarations
using namespace Slang;


namespace Sqlite3 {


class Sqlite3RowSeek : public Extensions::ExtensionMethod
{
public:
	Sqlite3RowSeek()
	: ExtensionMethod(0, "sqlite3_row_seek", Designtime::VoidType::TYPENAME)
	{
		ParameterList params;
		params.push_back(Parameter::CreateDesigntime("result", Designtime::Int32Type::TYPENAME));
		params.push_back(Parameter::CreateDesigntime("offset", Designtime::Int32Type::TYPENAME));

		setSignature(params);
	}

public:
	Runtime::ControlFlow::E execute( const ParameterList& params, Runtime::Object* /*result*/ )
	{
		ParameterList list = mergeParameters(params);

		ParameterList::const_iterator it = list.begin();

		int param_result = (*it++).value().toInt();
		int param_offset = (*it++).value().toInt();

		if ( param_result > 0 && param_result < (int)mResults.size() ) {
			mResults[param_result].rowSeek(param_offset);
		}

		return Runtime::ControlFlow::Normal;
	}
};


}


#endif
