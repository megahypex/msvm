#include <string>
#include <vector>
#include <iostream>

#include "util.hpp"

std::vector<std::string> str_split(std::string str, char c) {
    bool instrscope = false;
    std::vector<std::string> vec;
    std::string word = "";
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == c && !instrscope) {
            vec.push_back(word);
            word = "";
        } else if (str[i] == '\'' || str[i] == '"') {
            if (i != 0) {
                if (str[i - 1] != '\\') {
                    /* If string identifier has a backslash, skip */
                    instrscope = !instrscope;
                } else {
                    word += str[i];
                }
            } else {
                instrscope = !instrscope;
            }
        } else {
            word += str[i];
        }
    }

    if (word != "") {vec.push_back(word);}
    return vec;
}