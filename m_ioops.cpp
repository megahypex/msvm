#include <iostream>
#include <string>

#include "mvm_parse.hpp"
#include "m_obj.hpp"
#include "m_stackops.hpp"
#include "m_cstate.hpp"


void print_tab(cstate *state, m_obj *obj) {
    std::string text = "Table : {";
            
    /* get numeric keys */
    for (int i; i < obj->tabindexstor.size(); i++) {
        std::string val;
        m_obj elem = obj->tabindexstor[i];
                
        if (elem.v_type == FUNCTION) {
            val = "Function : " + elem.v_name;
        } else if (elem.v_type == TABLE) {
            val = "Table : " + elem.v_name;
        } else if (elem.v_type == CLASS) {
            val = "Class : " + elem.v_name;
        } else if (elem.v_type == CLASS_INS) {
            val = "Instance Of : " + state->getatmemaddr(elem.instanceof)->v_name;
        } else if (elem.v_type == STRING) {
            val = "\"" + elem.v_val + "\"";
        } else if (elem.v_type == NUMBER) {
            val = elem.v_val;
        }

        text = text + "[" + std::to_string(i) + "] = " + val;
        if (i != obj->tabindexstor.size() - 1) {
            text = text + "; ";
        }
    }

    for (auto& elem : obj->tabkeystor) {
        std::string val = "; ";
        if (elem.second.v_type == FUNCTION) {
            val = "Function : " + elem.second.v_name;
        } else if (elem.second.v_type == TABLE) {
            val = "Table : " + elem.second.v_name;
        } else if (elem.second.v_type == CLASS) {
            val = "Class : " + elem.second.v_name;
        } else if (elem.second.v_type == CLASS_INS) {
            val = "Instance Of : " + state->getatmemaddr(elem.second.instanceof)->v_name;
        } else if (elem.second.v_type == STRING) {
            val = "\"" + elem.second.v_val + "\"";
        } else if (elem.second.v_type == NUMBER) {
            val = elem.second.v_val;
        }

        text = text + "[\"" + elem.first + "\"] = " + val;
    }
}

void print_function(cstate *state, m_obj *obj) {
    std::cout << "Function : " + obj->v_name << '\n';
}

void print_class(cstate *state, m_obj *obj) {
    std::cout << "Class : " + obj->v_name << '\n';
}

void print_classins(cstate *state, m_obj *obj) {
    std::cout << "Instance Of : " + state->getatmemaddr(obj->instanceof)->v_name << '\n';
}

void print_str(cstate *state, std::string obj) {
    std::cout << obj << '\n';
}

void print_num(cstate *state, std::string obj) {
    std::cout << obj << '\n';
}

void print_univ(cstate *state, m_obj *obj) {
    /* Prints the type given "universal" print */
    switch (obj->v_type) {
        case FUNCTION: {
            print_function(state, obj);
            break;
        }
        case TABLE: {
            print_tab(state, obj);
            break;
        }
        case CLASS: {
            print_class(state, obj);
            break;
        }
        case CLASS_INS: {
            print_classins(state, obj);
            break;
        }
        case STRING: {
            print_str(state, obj->v_val);
            break;
        }
        case NUMBER: {
            print_num(state, obj->v_val);
            break;
        }
        default: {
            break;
        }
    }
}

void m_output(cstate *state, parseinfo info) {
    switch (info.type) {
        case I_MEM_ADDRESS: {
            /* Get whats at the memory address */
            print_univ(state, state->getatmemaddr(info));
            return;
        } 
        case I_STACK: {
            /* Get the top of the stack */
            print_univ(state, m_fetchstk(state, info.result));
            return;
        } 
        case STRING: {
            print_str(state, info.result);
        } 
        case NUMBER: {
            print_num(state, info.result);
        }
    }
}

void m_input(cstate *state, parseinfo stackinfo) {
    std::string input;
    std::getline(std::cin, input); /* get input */

    m_obj nobj;
    nobj.v_type = STRING;
    nobj.v_val = input;

    m_push(state, stackinfo, nobj); /* push as string to stack */
}
