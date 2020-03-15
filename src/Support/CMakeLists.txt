aux_source_directory(. SRC_SUP)
aux_source_directory(./Console/ SRC_SUP_CONSOLE)

message(${SRC_SUP_CONSOLE})

add_library(WSSupport SHARED 
    ${SRC_SUP}
    ${SRC_SUP_CONSOLE}    
)

target_include_directories(WSSupport PUBLIC 
    ./
    ../AbstractLang/

    ./Console/
)

target_link_libraries(WSSupport PUBLIC 
    WSAbstractLang
)
