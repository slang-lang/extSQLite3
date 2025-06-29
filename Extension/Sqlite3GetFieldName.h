
#ifndef Extensions_Sqlite3GetFieldName_h
#define Extensions_Sqlite3GetFieldName_h


// Library includes

// Project includes
#include "Defines.h"

// Forward declarations

// Namespace declarations
using namespace Slang;


namespace Sqlite3 {


class Sqlite3GetFieldName : public Extensions::ExtensionMethod
{
public:
    Sqlite3GetFieldName()
    : ExtensionMethod(0, "sqlite3_get_field_name", Designtime::StringType::TYPENAME)
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

        std::string fieldName;
        if ( param_result > 0 && param_result < (int)mResults.size() ) {
            fieldName = mResults[param_result].getCurrentFieldName();
        }

        *result = Runtime::StringType( fieldName );

        return Runtime::ControlFlow::Normal;
    }
};


class Sqlite3GetFieldNameByIndex : public Extensions::ExtensionMethod
{
public:
    Sqlite3GetFieldNameByIndex()
	: ExtensionMethod(0, "sqlite3_get_field_name", Designtime::StringType::TYPENAME)
	{
		ParameterList params;
		params.push_back(Parameter::CreateDesigntime("result", Designtime::Int32Type::TYPENAME));
        params.push_back(Parameter::CreateDesigntime("field_index", Designtime::Int32Type::TYPENAME));

		setSignature(params);
	}

public:
	Runtime::ControlFlow::E execute( const ParameterList& params, Runtime::Object* result )
	{
		ParameterList list = mergeParameters(params);

        ParameterList::const_iterator it = list.begin();

        auto param_result = (*it++).value().toInt();
        auto param_index = (*it++).value().toInt();

        std::string fieldName;
        if ( param_result > 0 && param_result < (int)mResults.size() ) {
            fieldName = mResults[param_result].getFieldNameByIndex(param_index);
        }

        *result = Runtime::StringType( fieldName );

		return Runtime::ControlFlow::Normal;
	}
};


}


#endif
