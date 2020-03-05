aux_source_directory(. SRC_ABSLANG)
aux_source_directory(Statement SRC_ABSLANG_STMT)
aux_source_directory(DataRepresentation SRC_ABSLANG_DR)
aux_source_directory(Environment SRC_ABSLANG_ENVR)
aux_source_directory(Expression SRC_ABSLANG_EXPR)

add_library(WSAbstractLang STATIC 
    # ${SRC_ABSLANG} 
    ${SRC_ABSLANG_STMT}
    ${SRC_ABSLANG_DR}
    ${SRC_ABSLANG_ENVR}
    ${SRC_ABSLANG_EXPR}
)

target_include_directories(WSAbstractLang
    PUBLIC
    ./
    Statement/
    DataRepresentation/
    Environment/
    Expression/
)

# --------------------- test1 ---------------------
add_executable(WSAbstractLangTest1 UnitTest1.cpp UTTool.cpp)

target_include_directories(WSAbstractLangTest1
    PUBLIC
    ./
    Statement/
    DataRepresentation/
    Environment/
    Expression/
)

target_link_libraries(WSAbstractLangTest1 WSAbstractLang)


# --------------------- test2 ---------------------
add_executable(WSAbstractLangTest2 UnitTest2.cpp UTTool.cpp)

target_include_directories(WSAbstractLangTest2
    PUBLIC
    ./
    Statement/
    DataRepresentation/
    Environment/
    Expression/
)

target_link_libraries(WSAbstractLangTest2 WSAbstractLang)


# --------------------- test3 ---------------------
add_executable(WSAbstractLangTest3 UnitTest3.cpp UTTool.cpp)

target_include_directories(WSAbstractLangTest3
    PUBLIC
    ./
    Statement/
    DataRepresentation/
    Environment/
    Expression/
)

target_link_libraries(WSAbstractLangTest3 WSAbstractLang)


# --------------------- test4 ---------------------
add_executable(WSAbstractLangTest4 UnitTest4.cpp UTTool.cpp)

target_include_directories(WSAbstractLangTest4
    PUBLIC
    ./
    Statement/
    DataRepresentation/
    Environment/
    Expression/
)

target_link_libraries(WSAbstractLangTest4 WSAbstractLang)
