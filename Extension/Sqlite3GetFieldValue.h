
#ifndef Extensions_Sqlite3GetFieldValue_h
#define Extensions_Sqlite3GetFieldValue_h


// Library includes

// Project includes
#include "Defines.h"

// Forward declarations

// Namespace declarations
using namespace Slang;


namespace Sqlite3 {


class Sqlite3GetFieldValue : public Extensions::ExtensionMethod
{
public:
    Sqlite3GetFieldValue()
    : ExtensionMethod(0, "sqlite3_get_field_value", Designtime::StringType::TYPENAME)
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

        std::string fieldValue;
        if ( param_result > 0 && param_result < (int)mResults.size() ) {
            fieldValue = mResults[param_result].getCurrentFieldValue();
        }

        *result = Runtime::StringType( fieldValue );

        return Runtime::ControlFlow::Normal;
    }
};

class Sqlite3GetFieldValueByIndex : public Extensions::ExtensionMethod
{
public:
	Sqlite3GetFieldValueByIndex()
	: ExtensionMethod(0, "sqlite3_get_field_value", Designtime::StringType::TYPENAME)
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

        int param_result = (*it++).value().toInt();
        int param_field_index = (*it++).value().toInt();

        std::string fieldValue;
        if ( param_result > 0 && param_result < (int)mResults.size() ) {
            fieldValue = mResults[param_result].getFieldValueByIndex(param_field_index);
        }

        *result = Runtime::StringType( fieldValue );

		return Runtime::ControlFlow::Normal;
	}
};


class Sqlite3GetFieldValueByName : public Extensions::ExtensionMethod
{
public:
    Sqlite3GetFieldValueByName()
    : ExtensionMethod(0, "sqlite3_get_field_value", Designtime::StringType::TYPENAME)
    {
        ParameterList params;
        params.push_back(Parameter::CreateDesigntime("result", Designtime::Int32Type::TYPENAME));
        params.push_back(Parameter::CreateDesigntime("field_name", Designtime::StringType::TYPENAME));

        setSignature(params);
    }

public:
    Runtime::ControlFlow::E execute( const ParameterList& params, Runtime::Object* result )
    {
        ParameterList list = mergeParameters(params);

        ParameterList::const_iterator it = list.begin();

        int param_result = (*it++).value().toInt();
        std::string param_field_name = (*it++).value().toStdString();

        std::string fieldValue;
        if ( param_result > 0 && param_result < (int)mResults.size() ) {
            fieldValue = mResults[param_result].getFieldValueByName(param_field_name);
        }

        *result = Runtime::StringType( fieldValue );

        return Runtime::ControlFlow::Normal;
    }
};


}


#endif
