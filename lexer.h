#pragma once

#include "./lexemes/boolean_literals.h"
#include "./lexemes/comment.h"
#include "./lexemes/identifier.h"
#include "./lexemes/keyword.h"
#include "./lexemes/lex.h"
#include "./lexemes/literal.h"
#include "./lexemes/num_literal.h"
#include "./lexemes/operator.h"
#include "./lexemes/string_literal.h"
#include "./lexemes/int_num.h"
#include "./lexemes/float_num.h"
#include "./lexemes/other.h"

#include "Bor.h"

#include <vector>
#include <iostream>
#include <fstream>
#include <unordered_set>

class Lexer {
public:
    void Scan(const std::string& file_name);
    void Print();
private:
    void ident(std::string& a);
    void comment_or_operator(std::string& a);
    void number_literal(std::string& a);
    void string_literal(std::string& a);
    void comment(std::string& a);
    void multi_comment(std::string& a);
    static bool is_letter(char c);
    static bool is_num(char c);
    bool is_oper(char c);
    std::fstream in;
    std::unordered_set<char> st = { '+', '-', '*', '/', '<', '>', '=', '%', '!', ',', '&', '|', '^' };
    Bor bor_;
    std::vector<Lex*> data_;
};
