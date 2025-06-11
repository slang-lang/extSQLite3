
#ifndef Extensions_Sqlite3Errcode_h
#define Extensions_Sqlite3Errcode_h


// Library includes

// Project includes
#include "Defines.h"

// Forward declarations

// Namespace declarations
using namespace Slang;


namespace Sqlite3 {


class Sqlite3Errcode : public Extensions::ExtensionMethod
{
public:
    Sqlite3Errcode()
	: ExtensionMethod(0, "sqlite3_errcode", Designtime::Int32Type::TYPENAME)
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

		int param_handle = (*it++).value().toInt();

		int errorCode = 0;
		if ( param_handle > 0 && param_handle < (int)mConnections.size() ) {
			errorCode = sqlite3_errcode( mConnections[param_handle] );
		}

		*result = Runtime::Int32Type( errorCode );

		return Runtime::ControlFlow::Normal;
	}
};


}


#endif
