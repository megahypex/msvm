#include <iostream>
#include <string>
#include "m_err.hpp"
#include "m_cstate.hpp"

void m_error(cstate *state, std::string str, enum ERR_TYPE type) {
    /* Show appropriate error type followed by the error */

    if (type == COMPILE_TIME) {
        std::cout << "Compile Time Error : \n";
    } else if (type == RUNTIME) {
        std::cout << "Runtime Error : \n";
    } else if (type == LEXING) {
        std::cout << "Error During Lexical Analysis : \n";
    } else if (type == PARSING) {
        std::cout << "Error While Parsing : \n";
    }

    std::cout << "Stack Begin\n";
    std::cout << str << '\n';
    std::cout << "On Line : " << state->line << "\n";
    /* Do the traceback */
    while (state->m_cstack.size() > 2) {
        int line = state->m_cstack.back().cline;

        if (line == -1) {break;} /* Protected function frame reached */
        m_frame frm = state->m_cstack.back();                                  /* Get the frame on top */
        std::cout << "Call On Line " << line << "\n";  /* Output Line Of Frame */
        state->m_cstack.pop_back();                                                /* Pop frame */
    }

    std::cout << "Stack End\n";
    exit(0);
}
