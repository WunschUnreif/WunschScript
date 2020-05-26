aux_source_directory(. SRC_WSVM_ByteCode)

add_library(WSVM_ByteCode STATIC 
    ${SRC_WSVM_ByteCode}
)

target_include_directories(WSVM_ByteCode PUBLIC 
    ./
)