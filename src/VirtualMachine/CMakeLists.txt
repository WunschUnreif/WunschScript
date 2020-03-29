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

# if(GEN_UT)
    
    add_executable(UTCodePrint UT/BCPrint.cpp)
    add_dependencies(UTCodePrint WSVirtualMachime)
    target_link_libraries(UTCodePrint PUBLIC WSVirtualMachime)

    add_executable(UTCodeBuild UT/BCBuild.cpp)
    add_dependencies(UTCodeBuild WSVirtualMachime)
    target_link_libraries(UTCodeBuild PUBLIC WSVirtualMachime)

# endif()

