
#ifndef Extensions_Sqlite3FreeResult_h
#define Extensions_Sqlite3FreeResult_h


// Library includes

// Project includes
#include "Defines.h"

// Forward declarations

// Namespace declarations
using namespace Slang;


namespace Sqlite3 {


class Sqlite3FreeResult : public Extensions::ExtensionMethod
{
public:
    Sqlite3FreeResult()
	: ExtensionMethod(0, "sqlite3_free_result", Designtime::VoidType::TYPENAME)
	{
		ParameterList params;
		params.push_back(Parameter::CreateDesigntime("result", Designtime::Int32Type::TYPENAME));

		setSignature(params);
	}

public:
	Runtime::ControlFlow::E execute( const ParameterList& params, Runtime::Object* /*result*/ )
	{
		ParameterList list = mergeParameters(params);

		ParameterList::const_iterator it = list.begin();

		auto param_result = (*it++).value().toInt();

		if ( param_result > 0 && param_result < (int)mResults.size() ) {
			mResults[param_result].clear();
		}

		return Runtime::ControlFlow::Normal;
	}
};


}


#endif
