aux_source_directory(. SRC_TRDG)

add_library(WSTreeDiagram STATIC
    ${SRC_TRDG}
)

target_include_directories(WSTreeDiagram PUBLIC 
    ./ 
    ../Syntaxer/
    ../AbstractLang/
    ../Parser/
    ../Support/

    ../../third/antlr4-cpp-runtime-4/runtime/src
)

# target_link_directories(WSTreeDiagram PUBLIC 
#     ../../third/antlr4-cpp-runtime-4/dist
# )

# target_link_libraries(WSTreeDiagram PUBLIC 
#     WSParser
#     WSAbstractLang
#     WSSyntaxer
#     libantlr4-runtime.a
# )
