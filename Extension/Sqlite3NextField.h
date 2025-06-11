
#ifndef Extensions_Sqlite3NextField_h
#define Extensions_Sqlite3NextField_h


// Library includes

// Project includes
#include "Defines.h"

// Forward declarations

// Namespace declarations
using namespace Slang;


namespace Sqlite3 {


class Sqlite3NextField : public Extensions::ExtensionMethod
{
public:
    Sqlite3NextField()
	: ExtensionMethod(0, "sqlite3_next_field", Designtime::Int32Type::TYPENAME)
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

		int nextField = 0;
		if ( param_result > 0 && param_result < (int)mResults.size() ) {
			nextField = mResults[param_result].nextField();
		}

		*result = Runtime::Int32Type( nextField );

		return Runtime::ControlFlow::Normal;
	}
};


}


#endif
