
// Header
#include "Extension.h"

// Library includes
#include <cassert>
#include <iostream>

// Project includes
#include "Sqlite3Close.h"
#include "Sqlite3Errcode.h"
#include "Sqlite3Errmsg.h"
#include "Sqlite3Exec.h"
#include "Sqlite3FieldCount.h"
#include "Sqlite3FieldSeek.h"
#include "Sqlite3FieldTell.h"
#include "Sqlite3FreeResult.h"
#include "Sqlite3GetFieldName.h"
#include "Sqlite3GetFieldValue.h"
#include "Sqlite3NextField.h"
#include "Sqlite3NextRow.h"
#include "Sqlite3Open.h"
#include "Sqlite3Rewind.h"
#include "Sqlite3RowCount.h"
#include "Sqlite3RowSeek.h"
#include "Sqlite3RowTell.h"

// Namespace declarations


namespace Sqlite3 {


Extension::Extension()
: AExtension( "extSQLite3", "0.3.0" )
{
	auto result = sqlite3_initialize();
	if ( result != SQLITE_OK ) {
		std::cerr << "Error while initializing sqlite3 extension!" << std::endl;
	}

	mName = "extSQLite3 (using libsqlite3 " + std::string( SQLITE_VERSION ) + ")";

	// initialize first connection which acts as invalid handle
	mConnections[0] = nullptr;
	// initialize first result which acts as invalid result "handle"
	mResults[0] = Sqlite3Result();
}

Extension::~Extension()
{
	sqlite3_shutdown();
}

void Extension::initialize( Slang::Extensions::ExtensionNamespace* scope )
{
   (void)scope;

   //std::cout << "Extension::initialize()" << std::endl;

   // global vars/consts currently don't work for extensions :-(
   scope->defineExternal( "SQLITE_OK", new Slang::Runtime::Int32Type( SQLITE_OK ) );
}

void Extension::provideMethods( Slang::Extensions::ExtensionMethods& methods )
{
	assert( methods.empty() );

	methods.push_back( new Sqlite3Close() );
	methods.push_back( new Sqlite3Errcode() );
	methods.push_back( new Sqlite3Errmsg() );
	methods.push_back( new Sqlite3Exec() );
	methods.push_back( new Sqlite3FieldCount() );
	methods.push_back( new Sqlite3FieldSeek() );
	methods.push_back( new Sqlite3FieldTell() );
	methods.push_back( new Sqlite3FreeResult() );
	methods.push_back( new Sqlite3GetFieldName() );
	methods.push_back( new Sqlite3GetFieldNameByIndex() );
	methods.push_back( new Sqlite3GetFieldValue() );
	methods.push_back( new Sqlite3GetFieldValueByIndex() );
	methods.push_back( new Sqlite3GetFieldValueByName() );
	methods.push_back( new Sqlite3NextField() );
	methods.push_back( new Sqlite3NextRow() );
	methods.push_back( new Sqlite3Open() );
	methods.push_back( new Sqlite3Rewind() );
	methods.push_back( new Sqlite3RowCount() );
	methods.push_back( new Sqlite3RowSeek() );
	methods.push_back( new Sqlite3RowTell() );
}


}


extern "C" Slang::Extensions::AExtension* factory( void ) {
	return dynamic_cast<Slang::Extensions::AExtension*>( new Sqlite3::Extension() );
}
