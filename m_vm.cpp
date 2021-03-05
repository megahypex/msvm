#include <iostream>
#include <string>

#include "m_obj.hpp"
#include "m_cstate.hpp"

int main() {
    cstate state;

    /* Create a main function and push a frame for it */
    state.instructions.push_back("push %d 'hello lol'");
    state.instructions.push_back("pop %d");
    m_frame mf;
    mf.cline = -1;
    mf.f_name = "$main";
    state.m_cstack.push_back(mf);    

    state.compute();
}
