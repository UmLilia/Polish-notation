#include "calculation.h"

#include <math.h>
#include <stdio.h>

#include "parsing.h"

double calculate_formula(char *formula) {
    StackOperand *operands_stack = init_operand(25);
    StackOperator *operators_stack = init_operator(25);
    double result = 0;
    for (int i = 0; formula[i] != '\0'; i++) {
        if (*(formula + i) >= 48 && *(formula + i) <= 57) {
            push_operand(operands_stack, parse_double_num(formula, &i, operators_stack));
        } else if (*(formula + i) == '(') {
            push_operator(operators_stack, *(formula + i));
        } else if (is_operator(*(formula + i))) {
            while (operators_stack->top > -1 &&
                   operator_priority(*(operators_stack->data + operators_stack->top)) >=
                       operator_priority(*(formula + i))) {
                free_pair(operands_stack, operators_stack);
            }
            push_operator(operators_stack, *(formula + i));
        } else if (*(formula + i) == ')') {
            while (operators_stack->top > -1 && *(operators_stack->data + operators_stack->top) != '(') {
                free_pair(operands_stack, operators_stack);
            }
            pop_operator(operators_stack);
            if (is_func(*(operators_stack->data + operators_stack->top))) {
                double arg = pop_operand(operands_stack);
                char func_ch = pop_operator(operators_stack);
                push_operand(operands_stack, func_execute(arg, func_ch));
            }
        } else if (*(formula + i) >= 97 && *(formula + i) <= 122) {
            char func_ch = parse_func(formula, &i);
            push_operator(operators_stack, func_ch);
        }
    }
    result = free_final(operands_stack, operators_stack);
    destroy_operand(operands_stack);
    destroy_operator(operators_stack);
    return result;
}

void free_pair(StackOperand *operands_stack, StackOperator *operators_stack) {
    char operation = pop_operator(operators_stack);
    double right = pop_operand(operands_stack);
    double left = pop_operand(operands_stack);
    double operation_result = operator_execute(left, right, operation);
    push_operand(operands_stack, operation_result);
}

double free_final(StackOperand *operands_stack, StackOperator *operators_stack) {
    while (operators_stack->top > -1) {
        free_pair(operands_stack, operators_stack);
    }
    return *(operands_stack->data + operands_stack->top);
}

double operator_execute(double left, double right, char operation) {
    double result = 0;
    if (operation == '*') {
        result = left * right;
    } else if (operation == '/') {
        result = left / right;
    } else if (operation == '+') {
        result = left + right;
    } else if (operation == '-') {
        result = left - right;
    }
    return result;
}

double func_execute(double arg, char mfunc) {
    double result = 0;
    if (mfunc == 'i')
        result = sin(arg);
    else if (mfunc == 'o')
        result = cos(arg);
    else if (mfunc == 'a')
        result = tan(arg);
    else if (mfunc == 't')
        result = ctg(arg);
    else if (mfunc == 'q')
        result = sqrt(arg);
    else if (mfunc == 'n')
        result = log(arg);
    return result;
}

double ctg(double arg) { return cos(arg) / sin(arg); }