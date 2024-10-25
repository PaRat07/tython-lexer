#pragma once

#include <string>

#include "lex.h"

class Comment : public Lex {
    void Print() {
        std::cout << "comment" << '\n';
    }
};
