aux_source_directory(. SRC_TRDG)

add_library(WSTreeDiagram STATIC
    ${SRC_TRDG}
)

target_include_directories(WSTreeDiagram PUBLIC 
    ./ 
    ../../Syntaxer/
    ../../AbstractLang/
    ../../Parser/
    ./Support/
    ../../ByteCode

    ../../../third/antlr4-cpp-runtime-4/runtime/src
)

add_subdirectory(Support)

add_dependencies(WSTreeDiagram WSSupport)

# target_link_directories(WSTreeDiagram PUBLIC 
#     ../../third/antlr4-cpp-runtime-4/dist
# )

# target_link_libraries(WSTreeDiagram PUBLIC 
#     WSParser
#     WSAbstractLang
#     WSSyntaxer
#     libantlr4-runtime.a
# )
