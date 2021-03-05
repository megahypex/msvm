#include <string>
#include "m_cstate.hpp"
#include "mvm_parse.hpp"

void m_push(cstate *state, parseinfo stkinfo, parseinfo valinfo);
void m_pop(cstate *state, parseinfo stkinfo);
m_obj m_fetchstk(cstate *state, std::string stkname);

