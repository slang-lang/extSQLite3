
#ifndef Extensions_Sqlite3Close_h
#define Extensions_Sqlite3Close_h


// Library includes

// Project includes
#include "Defines.h"

// Forward declarations

// Namespace declarations
using namespace Slang;


namespace Sqlite3 {


class Sqlite3Close : public Extensions::ExtensionMethod
{
public:
    Sqlite3Close()
	: ExtensionMethod(0, "sqlite3_close", Designtime::VoidType::TYPENAME)
	{
		ParameterList params;
		params.push_back(Parameter::CreateDesigntime("handle", Designtime::Int32Type::TYPENAME));

		setSignature(params);
	}

public:
	Runtime::ControlFlow::E execute( const ParameterList& params, Runtime::Object* /*result*/ )
	{
		ParameterList list = mergeParameters(params);

		ParameterList::const_iterator it = list.begin();

		auto param_handle = (*it++).value().toInt();

		if ( param_handle > 0 && param_handle < (int)mConnections.size() ) {
			sqlite3_close(mConnections[param_handle]);
		}

		return Runtime::ControlFlow::Normal;
	}
};


}


#endif
