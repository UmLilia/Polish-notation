#pragma once
#include "structures.h"

double calculate_formula(char *expression);
double operator_execute(double left, double right, char operation);
double func_execute(double arg, char mfunc);
void free_pair(StackOperand *operands_stack, StackOperator *operators_stack);
double free_final(StackOperand *operands_stack, StackOperator *operators_stack);
double ctg(double arg);