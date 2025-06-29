
#ifndef Extensions_Sqlite3Errmsg_h
#define Extensions_Sqlite3Errmsg_h


// Library includes

// Project includes
#include "Defines.h"

// Forward declarations

// Namespace declarations
using namespace Slang;


namespace Sqlite3 {


class Sqlite3Errmsg : public Extensions::ExtensionMethod
{
public:
    Sqlite3Errmsg()
	: ExtensionMethod(0, "sqlite3_errmsg", Designtime::StringType::TYPENAME)
	{
		ParameterList params;
		params.push_back(Parameter::CreateDesigntime("handle", Designtime::Int32Type::TYPENAME));

		setSignature(params);
	}

public:
	Runtime::ControlFlow::E execute( const ParameterList& params, Runtime::Object* result )
	{
		ParameterList list = mergeParameters(params);

		ParameterList::const_iterator it = list.begin();

		auto param_handle = (*it++).value().toInt();

		std::string errmsg;
		if ( param_handle > 0 && param_handle < (int)mConnections.size() ) {
			errmsg = sqlite3_errmsg( mConnections[param_handle] );
		}

		*result = Runtime::StringType( errmsg );

		return Runtime::ControlFlow::Normal;
	}
};


}


#endif
