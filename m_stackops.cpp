#include <iostream>
#include <string>
#include <stack>
#include "m_cstate.hpp"
#include "m_obj.hpp"
#include "m_lim.hpp"
#include "m_err.hpp"
#include "mvm_parse.hpp"

void m_push(cstate *state, parseinfo stkinfo, parseinfo valinfo) {
    /* Check if stack exists */
    if (state->stkstor.find(stkinfo.result) == state->stkstor.end()) {
        std::cout << "Stack `" << stkinfo.result << "` not found\n"; 
        exit(0);
    }

    /* Check if max stack value has reached */
    std::stack<m_obj> *stk = &(state->stkstor[stkinfo.result]);
    if (stk->size() == stack_lim) {
        m_error(state, "Internal Error : Stack Overflow while pushing", RUNTIME);
    }

    m_obj obj;
    obj.v_type = valinfo.type;
    obj.v_val = valinfo.result;

    /* Push */
    stk->push(obj);
}

void m_pop(cstate *state, parseinfo stkinfo) {
    /* Check if stack exists */
    if (state->stkstor.find(stkinfo.result) == state->stkstor.end()) {
        std::cout << "Stack `" << stkinfo.result << "` not found\n";
        exit(0);
    }

    /* Check if stack is empty */
    std::stack<m_obj> *stk = &(state->stkstor[stkinfo.result]);
     if (stk->empty()) {
         m_error(state, "Internal Error : Pop attempted on empty stack", RUNTIME);
     }
}

m_obj m_fetchstk(cstate *state, std::string stkname) {
    /* Check if stack exists */

    if (state->stkstor.find(stkname) == state->stkstor.end()) {
        std::cout << "Stack `" << stkname << "` not found\n";
        exit(0);
    }

    /* Check if stack is empty */
    std::stack<m_obj> *stk = &(state->stkstor[stkname]);
     if (stk->empty()) {
         m_error(state, "Internal Error : Fetch attempted on empty stack", RUNTIME);
     }

     return stk->top();
}