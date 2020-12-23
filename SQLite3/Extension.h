
#ifndef SQLite3_Extension_h
#define SQLite3_Extension_h


// Library includes

// Project includes
#include <Core/Extensions/AExtension.h>
#include "Defines.h"

// Forward declarations

// Namespace declarations


namespace Sqlite3 {


class Extension : public Slang::Extensions::AExtension
{
public:
    Extension();
    ~Extension();

public:
    void initialize( Slang::IScope* scope );
    void provideMethods( Slang::Extensions::ExtensionMethods& methods );
};


}


#endif
