#include "structures.h"

#include <stdlib.h>

StackOperand *init_operand(int size) {
    StackOperand *stack = (StackOperand *)malloc(sizeof(StackOperand));
    stack->top = -1;
    stack->size = size;
    stack->data = (double *)malloc(size * sizeof(double));
    return stack;
}

void push_operand(StackOperand *stack, double element) {
    if (stack->top + 1 == stack->size) {
        stack->size *= 2;
        stack->data = (double *)realloc(stack->data, stack->size * sizeof(double));
    }
    stack->top++;
    *(stack->data + stack->top) = element;
}

double pop_operand(StackOperand *stack) {
    double result = 0;
    if (stack->top > -1) {
        result = *(stack->data + stack->top);
        stack->top--;
    }
    return result;
}

void destroy_operand(StackOperand *stack) {
    free(stack->data);
    free(stack);
}

StackOperator *init_operator(int size) {
    StackOperator *stack = (StackOperator *)malloc(sizeof(StackOperator));
    stack->top = -1;
    stack->size = size;
    stack->data = (char *)malloc(size * sizeof(char));
    return stack;
}

void push_operator(StackOperator *stack, char element) {
    if (stack->top + 1 == stack->size) {
        stack->size *= 2;
        stack->data = (char *)realloc(stack->data, stack->size * sizeof(char));
    }
    stack->top++;
    *(stack->data + stack->top) = element;
}

char pop_operator(StackOperator *stack) {
    char result = 0;
    if (stack->top > -1) {
        result = *(stack->data + stack->top);
        stack->top--;
    }
    return result;
}

void destroy_operator(StackOperator *stack) {
    free(stack->data);
    free(stack);
}
