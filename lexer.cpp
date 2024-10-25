#include "lexer.h"

void Lexer::Scan(const std::string &file_name) {
    in.open(file_name);
    char tec_value;
    std::string buffer;
    while (in.get(tec_value)) {
        buffer.clear();
        if (is_letter(tec_value)) {
            buffer.push_back(tec_value);
            ident(buffer);
            continue;
        }
        if (is_oper(tec_value)) {
            buffer.push_back(tec_value);
            comment_or_operator(buffer);
            continue;
        }
        if (tec_value == '"') {
            string_literal(buffer);
            continue;
        }
        if (is_num(tec_value)) {
            buffer.push_back(tec_value);
            number_literal(buffer);
            continue;
        }
    }
}

void Lexer::ident(std::string &a) {
    char tec_value;
    bool is_other = false;
    if (is_letter(in.peek())) {
        while (in.peek() != ' ' && in.peek() != '\n' && in.peek() != EOF && in.peek() != ';') {
            in.get(tec_value);
            if (!is_letter(tec_value) && !is_num(tec_value)) {
                is_other = true;
            }
            a.push_back(tec_value);
        }
    }
    if (is_other) {
        if (a.back() == ')') {
            while (a.back() != '(') {
                a.pop_back();
            }
            a.pop_back();
            data_.push_back(new Identifier(a));
        } else {
            data_.push_back(new Other(a));
        }
    } else {
        if (bor_.find(a)) {
            data_.push_back(new Keyword(a));
        } else {
            data_.push_back(new Identifier(a));
        }
    }
}

void Lexer::comment_or_operator(std::string &a) {
    char tec_value;
    if (!is_oper(in.peek()) && !(a.front() == '/' && in.peek() == '/')
        && !(a.front() == '*' && in.peek() == '/')) {
        data_.push_back(new Operator(a));
        return;
    }
    in.get(tec_value);
    a.push_back(tec_value);
    if (tec_value == '/' && a.front() == '/') {
        comment(a);
    } else if (tec_value == '*' && a.front() == '/') {
        multi_comment(a);
    } else {
        data_.push_back(new Operator(a));
    }
}

void Lexer::string_literal(std::string &a) {
    char tec_value;
    in.get(tec_value);
    while (tec_value != '"') {
        a.push_back(tec_value);
        in.get(tec_value);
    }
    data_.push_back(new String_literal(a));
}

void Lexer::number_literal(std::string &a) {
    char tec_value;
    while (in.peek() != ' ' && in.peek() != '\n' && in.peek() != EOF) {
        in.get(tec_value);
        a.push_back(tec_value);
    }
    data_.push_back(new Int_num(a));
}

void Lexer::comment(std::string &a) {
    char tec_value;
    while (in.peek() != '\n') {
        in.get(tec_value);
    }
}

void Lexer::multi_comment(std::string &a) {
    char tec_value;
    while (in.get(tec_value) && !(in.peek() == '/' && tec_value == '*'));
    in.get(tec_value);
}


bool Lexer::is_letter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool Lexer::is_num(char c) {
    return c >= '0' && c <= '9';
}

bool Lexer::is_oper(char c) {
    return st.find(c) != st.end();
}

void Lexer::Print() {
    std::cout << data_.size() << '\n';
    for (int cnt = 0; auto &lexem : data_) {
        std::cout << cnt++ << ' ';
        lexem->Print();
    }
}
