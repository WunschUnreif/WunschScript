aux_source_directory(. SRC_INTP)

add_subdirectory(TreeDiagram)

add_executable(wunsch ${SRC_INTP})

target_include_directories(wunsch PUBLIC 
    ./ 
    ../Syntaxer/
    ../AbstractLang/
    ../Parser/
    ./TreeDiagram/
    ../ByteCode

    ../../third/antlr4-cpp-runtime-4/runtime/src
)

target_link_directories(wunsch PUBLIC 
    ../../third/antlr4-cpp-runtime-4/dist
)

target_link_libraries(wunsch PUBLIC 
    WSParser
    WSAbstractLang
    WSSyntaxer
    WSTreeDiagram
    WSSupport
    WSVM_ByteCode
    libantlr4-runtime.a
)

add_dependencies(wunsch WSTreeDiagram)
