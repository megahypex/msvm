#ifndef MVM_PARSE_HPP
#define MVM_PARSE_HPP

#include <string>
#include <vector>
#include "m_obj.hpp"

struct parseinfo {
    /* A structure which describes the parsing session */

    bool success;
    std::string result;
    enum V_TYPE type;

    /* optional */
    mem_index m_index;
};


parseinfo parse_str(std::string str);


#endif