#pragma once

typedef struct StackOperand {
    int top;
    int size;
    double *data;
} StackOperand;

typedef struct StackOperator {
    int top;
    int size;
    char *data;
} StackOperator;

StackOperand *init_operand(int size);
void push_operand(StackOperand *stack, double element);
double pop_operand(StackOperand *stack);
void destroy_operand(StackOperand *stack);

StackOperator *init_operator(int size);
void push_operator(StackOperator *stack, char element);
char pop_operator(StackOperator *stack);
void destroy_operator(StackOperator *stack);
