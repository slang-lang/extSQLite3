
#ifndef Extensions_Sqlite3NextRow_h
#define Extensions_Sqlite3NextRow_h


// Library includes

// Project includes
#include "Defines.h"

// Forward declarations

// Namespace declarations
using namespace Slang;


namespace Sqlite3 {


class Sqlite3NextRow : public Extensions::ExtensionMethod
{
public:
    Sqlite3NextRow()
	: ExtensionMethod(0, "sqlite3_next_row", Designtime::Int32Type::TYPENAME)
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

		int param_result = (*it++).value().toInt();

		int nextRow = 0;
		if ( param_result > 0 && param_result < (int)mResults.size() ) {
			nextRow = mResults[param_result].nextRow();
		}

		*result = Runtime::Int32Type( nextRow );

		return Runtime::ControlFlow::Normal;
	}
};


}


#endif
