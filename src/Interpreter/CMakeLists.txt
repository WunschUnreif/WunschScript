aux_source_directory(. SRC_INTP)

add_executable(WSInterpreter ${SRC_INTP})

target_include_directories(WSInterpreter PUBLIC 
    ./ 
    ../Syntaxer/
    ../AbstractLang/
    ../Parser/
    ../TreeDiagram/

    ../../third/antlr4-cpp-runtime-4/runtime/src
)

target_link_directories(WSInterpreter PUBLIC 
    ../../third/antlr4-cpp-runtime-4/dist
)

target_link_libraries(WSInterpreter PUBLIC 
    WSParser
    WSAbstractLang
    WSSyntaxer
    WSTreeDiagram
    libantlr4-runtime.a
)
