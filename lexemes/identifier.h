#pragma once

#include "lex.h"
#include <string>

class Identifier : public Lex {
public:
    std::string name_;
};