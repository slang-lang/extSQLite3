
#ifndef Extensions_Sqlite3Open_h
#define Extensions_Sqlite3Open_h


// Library includes

// Project includes
#include "Defines.h"

// Forward declarations

// Namespace declarations
using namespace Slang;


namespace Sqlite3 {


class Sqlite3Open : public Extensions::ExtensionMethod
{
public:
    Sqlite3Open()
	: ExtensionMethod(0, "sqlite3_open", Designtime::Int32Type::TYPENAME)
	{
		ParameterList params;
		params.push_back(Parameter::CreateDesigntime("file", Designtime::StringType::TYPENAME));

		setSignature(params);
	}

public:
	Runtime::ControlFlow::E execute( const ParameterList& params, Runtime::Object* result )
	{
		ParameterList list = mergeParameters(params);

		ParameterList::const_iterator it = list.begin();

		std::string param_file = (*it++).value().toStdString();

		size_t connection_handle = mConnections.size();
		sqlite3** database = &mConnections[connection_handle];

		int error = sqlite3_open(param_file.c_str(), database);

		*result = Runtime::Int32Type( static_cast<int>(error ? 0 : connection_handle) );

		return Runtime::ControlFlow::Normal;
	}
};


}


#endif
