#ifndef C_STATE
#define C_STATE

#include "m_obj.hpp"
#include "mvm_parse.hpp"
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>

struct cstate {
    std::vector<std::string> instructions;
    std::vector<m_frame> m_cstack;                                   /* Main caller stack */
    std::unordered_map<std::string, std::stack<m_obj>> stkstor;     /* Stack storage map */
    int line;
    int locpointer;
    /* Functions */
    cstate() {
        /* Create default stacks */
        std::stack<m_obj> d, f;

        cstate::line = 0;
        cstate::locpointer = 0;
        cstate::stkstor["%d"] = d;
        cstate::stkstor["%f"] = f;

        /* Make default frame */
        m_frame frm;
        frm.cline = -1;
        frm.f_name = "$root";

    }
    void compute();          
    std::vector<std::string> getfunc();
    m_obj* getatmemaddr(parseinfo info);
    m_obj* getatmemaddr(mem_index info);
};

#endif