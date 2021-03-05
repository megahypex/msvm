#include <iostream>
#include <string>

#include "m_cstate.hpp"
#include "mvm_parse.hpp"
#include "m_obj.hpp"
#include "m_stackops.hpp"

void m_output(cstate *state, parseinfo info) {
    if (info.type == I_MEM_ADDRESS) {
        /* Get whats at the memory address */
        m_obj *obj = state->getatmemaddr(info);

        if (obj->v_type == FUNCTION) {
            std::cout << "Function : " << obj->v_name << '\n';
            return;
        } else if (obj->v_type == TABLE) {
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

            for (std::pair<std::string, m_obj> elem : obj->tabkeystor) {
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
    } else if (info.type == I_STACK) {
        m_obj obj = m_fetchstk(state, info.result);
        
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
    }
}

void m_input(cstate *state, parseinfo stackinfo) {

}