#include <iostream>
#include <fstream>

#include "ByteCode.hpp"
#include "Opcode.hpp"

using namespace ws::vm;
ws::vm::ByteCode code;

void addInt64(int64_t num) {
    auto data = reinterpret_cast<uint8_t*>(&num);
    for(int i = 0; i < 8; ++i) {
        code.codeBuffer.push_back(data[i]);
    }
}

int64_t addDataString(std::string s) {
    int64_t res = code.dataBuffer.size();
    for(auto c : s) {
        code.dataBuffer.push_back(c);
    }
    code.dataBuffer.push_back(0);
    return res;
}

void addCode(ws::vm::OpCode x) {
    code.codeBuffer.push_back(x);
}

void init() {
    addCode(ws::vm::FILE);
    addInt64(addDataString("testcode"));

    addCode(ws::vm::LINE);
    addInt64(1);

    addCode(NAME);
    addInt64(addDataString("x"));

    addCode(IMMI);
    addInt64(10);

    addCode(SET);
    addInt64(addDataString("x"));

    addCode(GET);
    addInt64(addDataString("range"));

    addCode(PRECALL);
    addCode(IMMI);
    addInt64(10);
    addCode(ARG);
    addCode(CALL);
    
    addCode(ITER);
    addInt64(addDataString("i"));

    addCode(PROC);
    addInt64(38);

    addCode(GET);
    addInt64(addDataString("x"));

    addCode(GET);
    addInt64(addDataString("i"));

    addCode(ADD);

    addCode(SET);
    addInt64(addDataString("x"));

    addCode(ENDPS);
    addCode(NEXT);
    addInt64(-47);
}

int main() {
    init();

    std::cout << code.ToString() << std::endl;

    std::ifstream ifile("testcode.wsc", std::ios::binary);
    ByteCode loaded(ifile);

    std::cout << loaded.ToString() << std::endl;

    return 0;
}

/*
    var x = 10;     name "x"
                    immI 10
                    set @("x")

    for i in range(10)          get "range"
                                precall
                                immI 10
                                arg
                                call
                                iter "i"
    {                           proc 29
        x = x + i;                  get "x"
                                    get "i"
                                    add
                                    set "x"
    }                           endps
                                next -(47)

*/
