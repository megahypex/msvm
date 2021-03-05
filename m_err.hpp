#ifndef ERR_HPP
#define ERR_HPP
#include <string>
#include "m_cstate.hpp"

enum ERR_TYPE {COMPILE_TIME, RUNTIME, LEXING, PARSING};

void m_error(cstate *state, std::string str, enum ERR_TYPE type);


#endif