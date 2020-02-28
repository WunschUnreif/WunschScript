aux_source_directory(. SRC_ABSLANG)
aux_source_directory(Statement SRC_ABSLANG_STMT)
aux_source_directory(DataRepresentation SRC_ABSLANG_DR)
aux_source_directory(Environment SRC_ABSLANG_ENVR)
aux_source_directory(Expression SRC_ABSLANG_EXPR)

add_library(WSAbstractLang STATIC 
    # ${SRC_ABSLANG} 
    ${SRC_ABSLANG_STMT}
    ${SRC_ABSLANG_DR}
    ${SRC_ABSLANG_ENVR}
    ${SRC_ABSLANG_EXPR}
)

target_include_directories(WSAbstractLang
    PUBLIC
    ./
    Statement/
    DataRepresentation/
    Environment/
    Expression/
)

add_executable(WSAbstractLangTest ${SRC_ABSLANG})

target_include_directories(WSAbstractLangTest
    PUBLIC
    ./
    Statement/
    DataRepresentation/
    Environment/
    Expression/
)

target_link_libraries(WSAbstractLangTest WSAbstractLang)
