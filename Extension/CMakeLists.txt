INCLUDE(${PROJECT_SOURCE_DIR}/CMake/Base.cmake)

SET(SOURCES
    Extension.cpp
    Types.cpp
)

SET(HEADERS
    Defines.h
    Extension.h
    Sqlite3Close.h
    Sqlite3Column.h
    Sqlite3Errcode.h
    Sqlite3Errmsg.h
    Sqlite3Exec.h
    Sqlite3FieldCount.h
    Sqlite3FieldSeek.h
    Sqlite3FieldTell.h
    Sqlite3FreeResult.h
    Sqlite3GetFieldName.h
    Sqlite3GetFieldValue.h
    Sqlite3NextField.h
    Sqlite3NextRow.h
    Sqlite3Open.h
    Sqlite3Result.h
    Sqlite3Rewind.h
    Sqlite3Row.h
    Sqlite3RowCount.h
    Sqlite3RowSeek.h
    Sqlite3RowTell.h
    Types.h
)

SET(DEPENDENCIES
    Core
    sqlite3
)

SET(MODULES
    slang
)

add_include(Externals)

build_shared_lib(SlangSQLite3 "${MODULES}")

