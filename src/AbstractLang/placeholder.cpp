#include "Statement/Statement.hpp"

class SomeStatement : public ws::asl::StatementBase {
    void execute(const ws::asl::Environment & env) {
        return;
    }
};

SomeStatement stmt;
