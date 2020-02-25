aux_source_directory(. SRC_ABSLANG)
aux_source_directory(Statement SRC_ABSLANG_STMT)

add_library(WSAbstractLang STATIC 
    ${SRC_ABSLANG} 
    ${SRC_ABSLANG_STMT}
)

target_include_directories(WSAbstractLang
    PUBLIC
    ./Statement
)
