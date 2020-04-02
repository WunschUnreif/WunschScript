aux_source_directory(. SRC_VM)
aux_source_directory(DataRepresentation SRC_VM_DR)

add_subdirectory(Bytecode/)

add_library(WSVirtualMachine 
    ${SRC_VM}
    ${SRC_VM_DR}
)

target_include_directories(WSVirtualMachine PUBLIC 
    ./
    DataRepresentation/
)

if(GEN_UT)
    
    add_executable(UTCodePrint UT/BCPrint.cpp)
    add_dependencies(UTCodePrint WSVM_ByteCode)
    target_include_directories(UTCodePrint PUBLIC ./)
    target_link_libraries(UTCodePrint PUBLIC WSVM_ByteCode)

    add_executable(UTCodeBuild UT/BCBuild.cpp)
    add_dependencies(UTCodeBuild WSVM_ByteCode)
    target_link_libraries(UTCodeBuild PUBLIC WSVM_ByteCode)
    target_include_directories(UTCodeBuild PUBLIC ./)

endif()

