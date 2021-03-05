#ifndef OBJ_HPP
#define OBJ_HPP
#include <string>
#include <stack>
#include <vector>
#include <unordered_map>

enum V_TYPE {
  FUNCTION,
  STRING,
  NUMBER,
  TABLE,
  VARIABLE,
  CLASS,
  CLASS_INS,

  I_STACK,      /* I - Internal */
  I_MEM_ADDRESS
};

struct mem_index {
  /* Stores memory index data */
  int frmindex;
  int valindex;
};

struct m_obj {
  std::string v_name;
  enum V_TYPE v_type;
  std::string v_val;
  mem_index v_addr;

  /* function */
  std::vector<std::string> f_ins;

  /* table / dictionary */
  std::vector<m_obj> tabindexstor;                    /* For storing index / value pairs */
  std::unordered_map<std::string, m_obj> tabkeystor;  /* For storing key / value pairs */

  /* Class */
  bool priv;              /* Is private? */
  mem_index instanceof;   /* Stores the class it instanciated from */
};


struct m_frame {
  /*
    Stores local variables of a functions
    Variables and functions are pushed in after initialization
  */

  std::string f_name;     /* Function name */
  int cline;              /* Line at which it was called */
  std::vector<m_obj> con; /* Container for local vars */
};


#endif