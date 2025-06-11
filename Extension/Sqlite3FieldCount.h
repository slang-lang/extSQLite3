
#ifndef Extensions_Sqlite3FieldCount_h
#define Extensions_Sqlite3FieldCount_h


// Library includes

// Project includes
#include "Defines.h"

// Forward declarations

// Namespace declarations
using namespace Slang;


namespace Sqlite3 {


class Sqlite3FieldCount : public Extensions::ExtensionMethod
{
public:
    Sqlite3FieldCount()
	: ExtensionMethod(0, "sqlite3_field_count", Designtime::Int32Type::TYPENAME)
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

		int fieldCount = 0;

		if ( param_result > 0 && param_result < (int)mResults.size() ) {
			fieldCount = mResults[param_result].fieldCount();
		}

		*result = Runtime::Int32Type( fieldCount );

		return Runtime::ControlFlow::Normal;
	}
};


}


#endif
