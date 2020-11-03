#include "stack.h"
#include<cstdlib>

bool is_operand (const char* token) {
  return ((token[0] >= '0') and (token[0] <= '9'));
}

bool is_unary_minus (const char* token) {
  return token[0] == '!';
}

bool is_plus (const char* token) {
  return token[0] == '+';
}

bool is_minus (const char* token) {
  return token[0] == '-';
}

bool is_mult (const char* token) {
  return token[0] == 'x';
}

bool is_div (const char* token) {
  return token[0] == '/';
}

bool is_operator (const char* token) {
  return (is_unary_minus(token)
          or is_plus(token)
          or is_minus(token)
          or is_mult(token)
          or is_div(token));
}

int rpn_eval (int n, const char* expr []) {
  int* stack = init_stack(n);
  int top = 0;
  for (int i = 0; i < n; i++) {
    const char* token = expr[i];
    if (is_operand(token))
      push(stack, &top, atoi(token));
    else if (is_operator(token)) {
      if (is_unary_minus(token)) {
        int val = pop(stack, &top);
        push(stack, &top, -val);
      } else {
        int val2 = pop(stack, &top);
        int val1 = pop(stack, &top);
        if (is_plus(token))
          push(stack, &top, val1+val2);
        else if (is_minus(token))
          push(stack, &top, val1-val2);
        else if (is_mult(token))
          push(stack, &top, val1*val2);
        else if (is_div(token))
          push(stack, &top, val1/val2);
      }
    }
  }
  int result = stack[0];
  delete_stack(stack);
  return result;
}