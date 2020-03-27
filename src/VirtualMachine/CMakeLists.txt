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

# if(BUILD_UT)
    
    add_executable(UTCodePrint UT/BCPrint.cpp)
    add_dependencies(UTCodePrint WSVirtualMachime)
    target_link_libraries(UTCodePrint PUBLIC WSVirtualMachime)

# endif()

