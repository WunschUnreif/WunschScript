aux_source_directory(. SRC_VM)

aux_source_directory(Bytecode/ SRC_VM_BYTECODE)

add_library(WSVirtualMachime STATIC 
    ${SRC_VM}
    ${SRC_VM_BYTECODE}
)

target_include_directories(WSVirtualMachime PUBLIC 
    ./
    ../
)
