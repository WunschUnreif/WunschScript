aux_source_directory(. SRC_SYN_MAIN)

add_library(WSSyntaxer STATIC ${SRC_SYN_MAIN})

target_include_directories(WSSyntaxer PUBLIC
    ./
    ../Parser/
    
    ../AbstractLang/
    ../ByteCode

    ../../third/antlr4-cpp-runtime-4/runtime/src
)

add_dependencies(WSSyntaxer WSAbstractLang)

if(GEN_UT)

    # ---------------- test 1 ----------------
    add_executable(WSSyntaxerTest1 UT/UnitTest1.cpp)

    target_include_directories(WSSyntaxerTest1 PUBLIC
        UT/

        ./
        ../Parser/
        
        ../AbstractLang/
        ../AbstractLang/Statement/
        ../AbstractLang/DataRepresentation/
        ../AbstractLang/Environment/
        ../AbstractLang/Expression/

        ../../third/antlr4-cpp-runtime-4/runtime/src
    )

    target_link_directories(WSSyntaxerTest1 PUBLIC 
        ../../third/antlr4-cpp-runtime-4/dist
    )

    target_link_libraries(WSSyntaxerTest1 PUBLIC 
        WSParser
        WSAbstractLang
        WSSyntaxer
        WSVM_ByteCode
        libantlr4-runtime.a
    )

    # ---------------- test 2 ----------------
    add_executable(WSSyntaxerTest2 UT/UnitTest2.cpp)

    target_include_directories(WSSyntaxerTest2 PUBLIC
        UT/

        ./
        ../Parser/

        ../../third/antlr4-cpp-runtime-4/runtime/src
    )

    target_link_directories(WSSyntaxerTest2 PUBLIC 
        ../../third/antlr4-cpp-runtime-4/dist
    )

    target_link_libraries(WSSyntaxerTest2 PUBLIC 
        WSParser
        WSAbstractLang
        WSSyntaxer
        WSVM_ByteCode
        libantlr4-runtime.a
    )

endif()
