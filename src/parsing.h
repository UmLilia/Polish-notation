#pragma once
#include "structures.h"
typedef double (*math_func)(double);

int is_operator(char ch);
int operator_priority(char operator);
double parse_double_num(const char *formula, int *i, StackOperator *stack);
int is_func(char ch);
char parse_func(const char *formula, int *i);
void replace_x(char *dest, const char *formula, char *new_val);
int check_valid(char *formula);