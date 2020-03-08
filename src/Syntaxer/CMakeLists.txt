aux_source_directory(. SRC_SYN_MAIN)

add_library(WSSyntaxer STATIC ${SRC_SYN_MAIN})

target_include_directories(WSSyntaxer PUBLIC
    ./
    ../Parser/
    
    ../AbstractLang/
    ../AbstractLang/Statement/
    ../AbstractLang/DataRepresentation/
    ../AbstractLang/Environment/
    ../AbstractLang/Expression/

    ../../third/antlr4-cpp-runtime-4/runtime/src
)

if(BUILD_UT)

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
        libantlr4-runtime.a
    )

endif()
