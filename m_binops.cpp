#include <stack>
#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>

#include "m_err.hpp"
#include "m_obj.hpp"
#include "m_cstate.hpp"
#include "m_binops.hpp"

void checkstk(cstate *state, parseinfo stkinfo) {
    std::stack<m_obj> stk = state->stkstor[stkinfo.result];

    if (stk.size() < 2) {
        m_error(state, "Not enough elements to conduct binop", RUNTIME);
        exit(0);
    }

    m_obj top1 = stk.top(); stk.pop();
    m_obj top2 = stk.top();

    if (top1.v_type != NUMBER || top2.v_type != NUMBER) {
        m_error(state, "Incompatible type for binop", RUNTIME);
        exit(0);
    }
}

void finishbinop(cstate *state, parseinfo stkinfo, longd ans) {
    std::string nans = std::fmod(ans, 1.0) == 0 ? std::to_string((bigint) ans) : std::to_string(ans);
    std::stack<m_obj> *stk = &(state->stkstor[stkinfo.result]);

    m_obj obj;
    obj.v_val = nans;
    obj.v_type = NUMBER;

    stk->push(obj);
}

void m_addstk(cstate *state, parseinfo stkinfo) {
    checkstk(state, stkinfo);
    std::stack<m_obj> *stk = &(state->stkstor[stkinfo.result]);
    
    m_obj top1 = stk->top(); stk->pop();
    m_obj top2 = stk->top();

    longd dtop1 = std::stold(top1.v_val);
    longd dtop2 = std::stold(top2.v_val);

    finishbinop(state, stkinfo, dtop1 + dtop2);
}

void m_substk(cstate *state, parseinfo stkinfo) {
    checkstk(state, stkinfo);
    std::stack<m_obj> *stk = &(state->stkstor[stkinfo.result]);
    
    m_obj top1 = stk->top(); stk->pop();
    m_obj top2 = stk->top();

    longd dtop1 = std::stold(top1.v_val);
    longd dtop2 = std::stold(top2.v_val);

    finishbinop(state, stkinfo, dtop2 - dtop1);
}

void m_mulstk(cstate *state, parseinfo stkinfo) {
    checkstk(state, stkinfo);
    std::stack<m_obj> *stk = &(state->stkstor[stkinfo.result]);
    
    m_obj top1 = stk->top(); stk->pop();
    m_obj top2 = stk->top();

    longd dtop1 = std::stold(top1.v_val);
    longd dtop2 = std::stold(top2.v_val);

    finishbinop(state, stkinfo, dtop2 * dtop1);
}

void m_divstk(cstate *state, parseinfo stkinfo) {
    checkstk(state, stkinfo);
    std::stack<m_obj> *stk = &(state->stkstor[stkinfo.result]);
    
    m_obj top1 = stk->top(); stk->pop();
    m_obj top2 = stk->top();

    longd dtop1 = std::stold(top1.v_val);
    longd dtop2 = std::stold(top2.v_val);

    finishbinop(state, stkinfo, dtop1 / dtop2);
}

void m_modstk(cstate *state, parseinfo stkinfo) {
    checkstk(state, stkinfo);
    std::stack<m_obj> *stk = &(state->stkstor[stkinfo.result]);
    
    m_obj top1 = stk->top(); stk->pop();
    m_obj top2 = stk->top();

    longd dtop1 = std::stold(top1.v_val);
    longd dtop2 = std::stold(top2.v_val);

    finishbinop(state, stkinfo, std::fmod(dtop2, dtop1));
}

void m_powstk(cstate *state, parseinfo stkinfo) {
    checkstk(state, stkinfo);
    std::stack<m_obj> *stk = &(state->stkstor[stkinfo.result]);
    
    m_obj top1 = stk->top(); stk->pop();
    m_obj top2 = stk->top();

    longd dtop1 = std::stold(top1.v_val);
    longd dtop2 = std::stold(top2.v_val);

    finishbinop(state, stkinfo, std::pow(dtop2, dtop1));
}