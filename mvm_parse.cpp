/* 

Parser for the vm
Trying to make this as lightweight as possible
*/
#include <iostream>
#include <string>
#include "mvm_parse.hpp"
#include "m_obj.hpp"

std::string ctostr(char x) {
    std::string str(1, x);
    return str;
}

parseinfo parse_str(std::string str) {
    parseinfo result;
    result.success = true;

    if (str[0] == '%') {
        /* Stack */
        result.result = str;
        result.type = I_STACK;
        return result;    
    } else if (ctostr(str[0]).find_first_of("0123456789") == 0) {
        /* Number */
        result.result = str;
        result.type = NUMBER;
        return result;
    } else if (str[0] == '[') {
        /* Memory Index */
        
        mem_index memoryindex;
        result.type = I_MEM_ADDRESS;
        /* Find first ending `]` */             // [f-1][0]
        int pos = str.find_first_of(']');
        str.erase(pos, 1);
        str.erase(0, 1);
        /* Get the frame index */
        
        if (str[1] == '-') {
            
            memoryindex.frmindex = std::stoi(str.substr(2, pos-1));
            str.erase(0, pos-1);
        } else {
            memoryindex.frmindex = 0;
            str.erase(0, 1);
        }

        int pos2 = str.find_first_of(']');

        // Get the value index 
        str.erase(0, 1);
        if (str[0] == '-') {
            memoryindex.valindex = std::stoi(str.substr(1, pos2 - 1));
        } else {
            memoryindex.valindex = 0;
        }

        result.m_index = memoryindex;
        return result;

    } else {
        /* String */
        result.result = str;
        result.type = STRING;
        return result;
    }
}




