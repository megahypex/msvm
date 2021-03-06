#include <iostream>
#include <stack>
#include <string>
#include "m_cstate.hpp"
#include "m_obj.hpp"
#include "util.hpp"
#include "mvm_parse.hpp"

#include "m_stackops.hpp"
#include "m_ioops.hpp"

void cstate::compute() {
    /* Checks */
    if (this->instructions.size() == 0) {return;}

    /* Computation */
    while (this->locpointer < this->instructions.size()) {
        std::string input = this->instructions.at(this->locpointer);
        std::vector<std::string> args = str_split(input, ' ');
        if (input[input.size() - 1] == ':') {
            /* If last character is a label end marker */
            /* Start scanning the function until another return is found */

            input.erase(input.size() - 1, 1);
            std::vector<std::string> ins = this->getfunc();
            
            m_obj newo;
            newo.v_name = input;
            newo.v_type = FUNCTION;
            newo.f_ins = ins;
            m_frame *tframe = &(this->m_cstack.back());
            tframe->con.push_back(newo);
            continue;
        } else if (args[0] == "push") { 
            parseinfo stackinf = parse_str(args[1]);
            parseinfo valueinf = parse_str(args[2]);
            
            m_obj nobj;
            nobj.v_type = valueinf.type;
            nobj.v_val = valueinf.result;

            m_push(this, stackinf, nobj);
        } else if (args[0] == "pop") {
            parseinfo stackinf = parse_str(args[1]);

            m_pop(this, stackinf);
        } else if (args[0] == "out") {
            parseinfo valinf = parse_str(args[1]);

            m_output(this, valinf);
        } else if (args[0] == "inp") {
            parseinfo stackinf = parse_str(args[1]);

            m_input(this, stackinf);     
        } else {
            std::cout << "Unknown Token" << std::endl;
            exit(0);
        }

        this->locpointer += 1;
    }
}


std::vector<std::string> cstate::getfunc() {
    /* Function ends when scope index is 0, otherwise keeps going */
    int scopeindex = 1; 
    std::vector<std::string> ins;    /* Stack to store obtained instructions */
    this->locpointer += 1;
    while (scopeindex != 0 && this->locpointer > this->instructions.size()) {
        std::string input = this->instructions.at(this->locpointer);
        if (input.at(input.size() - 1) == ':') {
            scopeindex += 1;
        } else if(input == "ret") {
            scopeindex -= 1;
        }

        ins.push_back(input);
        this->locpointer += 1;
    }

    return ins;
}

m_obj* cstate::getatmemaddr(parseinfo info) {
    int rfindex = (this->m_cstack.size() - 1) - info.m_index.frmindex;
    int rvindex = (this->m_cstack[rfindex].con.size() - 1) - info.m_index.valindex;

    return &(this->m_cstack[rfindex].con[rvindex]);
}

m_obj* cstate::getatmemaddr(mem_index info) {
    int rfindex = (this->m_cstack.size() - 1) - info.frmindex;
    int rvindex = (this->m_cstack[rfindex].con.size() - 1) - info.valindex;
    
    return &(this->m_cstack[rfindex].con[rvindex]);
}