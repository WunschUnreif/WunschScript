aux_source_directory(. SRC_ABSLANG)
aux_source_directory(Statement SRC_ABSLANG_STMT)
aux_source_directory(DataRepresentation SRC_ABSLANG_DR)
aux_source_directory(Environment SRC_ABSLANG_ENVR)
aux_source_directory(Expression SRC_ABSLANG_EXPR)
aux_source_directory("Program/" SRC_ABSLANG_PROG)

add_library(WSAbstractLang STATIC 
    ${SRC_ABSLANG_STMT}
    ${SRC_ABSLANG_DR}
    ${SRC_ABSLANG_ENVR}
    ${SRC_ABSLANG_EXPR}
    ${SRC_ABSLANG_PROG}
)

target_include_directories(WSAbstractLang
    PUBLIC
    ./
    Statement/
    DataRepresentation/
    Environment/
    Expression/
    Program/
)


if(GEN_UT)

    # --------------------- test1 ---------------------
    # add_executable(WSAbstractLangTest1 UT/UnitTest1.cpp UT/UTTool.cpp)

    # target_include_directories(WSAbstractLangTest1
    #     PUBLIC
    #     ./
    #     Statement/
    #     DataRepresentation/
    #     Environment/
    #     Expression/
    #     UT/
    # )

    # target_link_libraries(WSAbstractLangTest1 WSAbstractLang)


    # --------------------- test2 ---------------------
    add_executable(WSAbstractLangTest2 UT/UnitTest2.cpp UT/UTTool.cpp)

    target_include_directories(WSAbstractLangTest2
        PUBLIC
        ./
        Statement/
        DataRepresentation/
        Environment/
        Expression/
        "Program/"
        UT/
    )

    target_link_libraries(WSAbstractLangTest2 WSAbstractLang)


    # --------------------- test3 ---------------------
    add_executable(WSAbstractLangTest3 UT/UnitTest3.cpp UT/UTTool.cpp)

    target_include_directories(WSAbstractLangTest3
        PUBLIC
        ./
        Statement/
        DataRepresentation/
        Environment/
        Expression/
        "Program/"
        UT/
    )

    target_link_libraries(WSAbstractLangTest3 WSAbstractLang)


    # --------------------- test4 ---------------------
    add_executable(WSAbstractLangTest4 UT/UnitTest4.cpp UT/UTTool.cpp)

    target_include_directories(WSAbstractLangTest4
        PUBLIC
        ./
        Statement/
        DataRepresentation/
        Environment/
        Expression/
        "Program/"
        UT/
    )

    target_link_libraries(WSAbstractLangTest4 WSAbstractLang)

endif()
