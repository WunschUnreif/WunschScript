aux_source_directory(. SRC_VM)

aux_source_directory(Bytecode/ SRC_VM_BYTECODE)

add_library(WSVirtualMachine STATIC 
    ${SRC_VM}
    ${SRC_VM_BYTECODE}
)

target_include_directories(WSVirtualMachine PUBLIC 
    ./
    ../
)

# if(GEN_UT)
    
    add_executable(UTCodePrint UT/BCPrint.cpp)
    add_dependencies(UTCodePrint WSVirtualMachine)
    target_link_libraries(UTCodePrint PUBLIC WSVirtualMachine)

    add_executable(UTCodeBuild UT/BCBuild.cpp)
    add_dependencies(UTCodeBuild WSVirtualMachine)
    target_link_libraries(UTCodeBuild PUBLIC WSVirtualMachine)

# endif()

