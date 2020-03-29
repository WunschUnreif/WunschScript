aux_source_directory(. SRC_SUP)
aux_source_directory(./Console/ SRC_SUP_CONSOLE)
aux_source_directory(./List/ SRC_SUP_LIST)


add_library(WSSupport STATIC 
    ${SRC_SUP}
    ${SRC_SUP_CONSOLE}    
    ${SRC_SUP_LIST}
)

target_include_directories(WSSupport PUBLIC 
    ./
    ....//AbstractLang/

    ./Console/
    ./List/
)

add_dependencies(WSSupport WSAbstractLang)

target_link_libraries(WSSupport PUBLIC 
    WSAbstractLang
)
