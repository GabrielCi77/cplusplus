#include "stack.h"
#include<cstdlib>

bool is_operand (char* token);
bool is_unary_minus (char* token);
bool is_plus (char* token);
bool is_minus (char* token);
bool is_mult (char* token);
bool is_div (char* token);
bool is_operator (char* token);
int rpn_eval (int n, const char* expr []);


