#include "m_cstate.hpp"

typedef long double longd;
typedef long int bigint;

void checkstk(cstate *state, parseinfo stkinfo);   /* Function to check if stack meets conditions */
void finishbinop(cstate *state, parseinfo stkinfo, longd ans); 

void m_addstk(cstate *state, parseinfo stkinfo);   /* Addition */
void m_substk(cstate *state, parseinfo stkinfo);   /* Subtraction */
void m_mulstk(cstate *state, parseinfo stkinfo);   /* Multiplication */
void m_divstk(cstate *state, parseinfo stkinfo);   /* Division */
void m_modstk(cstate *state, parseinfo stkinfo);   /* Modulus */
void m_powstk(cstate *state, parseinfo stkinfo);   /* Power */

