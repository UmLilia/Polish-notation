#include "parsing.h"

#include <math.h>
#include <stdio.h>
#include <string.h>

int is_operator(char ch) {
    const int n = 4;
    const char operators[] = {'*', '/', '+', '-'};
    int flag = 0;
    for (int i = 0; !flag && i < n; i++) {
        if (ch == operators[i]) {
            flag = 1;
        }
    }
    return flag;
}

int is_func(char ch) {
    const int n = 6;
    const char funcs[] = {'i', 'o', 'a', 't', 'q', 'n'};
    int flag = 0;
    for (int i = 0; !flag && i < n; i++) {
        if (ch == funcs[i]) {
            flag = 1;
        }
    }
    return flag;
}

int operator_priority(char operator) {
    int priority = 0;

    if (operator== '*' || operator== '/')
        priority = 2;
    else if (operator== '+' || operator== '-')
        priority = 1;
    else if (operator== '(')
        priority = 0;
    return priority;
}

double parse_double_num(const char *formula, int *i, StackOperator *stack) {
    double result;
    char buffer[32] = {'0'};
    int len = 0;
    int flag_minus = 0;
    if (*i > 1 && formula[*i - 1] == '-' && formula[*i - 2] == '(') {
        pop_operator(stack);
        flag_minus = 1;
    }

    while ((formula[*i] >= 48 && formula[*i] <= 57) || formula[*i] == '.') {
        buffer[len] = formula[*i];
        (*i)++;
        len++;
    }
    sscanf(buffer, "%lf", &result);
    (*i)--;
    return flag_minus ? -result : result;
}

char parse_func(const char *formula, int *i) {
    char buffer[16] = {'\0'};
    int len = 0;
    while (formula[*i] >= 97 && formula[*i] <= 122) {
        buffer[len] = formula[*i];
        (*i)++;
        len++;
    }
    (*i)--;
    return buffer[1];
}

void replace_x(char *dest, const char *formula, char *new_val) {
    char buffer[256];
    int val_len = strlen(new_val);
    int len = 0;
    for (int i = 0; formula[i] != '\0'; i++) {
        if (formula[i] != 'x') {
            buffer[len] = formula[i];
            len++;
        } else {
            strcpy(buffer + len, new_val);
            len += val_len;
        }
    }
    buffer[len] = '\0';
    strcpy(dest, buffer);
}

int check_valid(char *formula) {
    int flag = 1;
    int count_space = 0;
    int open_bracket = 0;
    int close_bracket = 0;
    char *valid_symbols = ".xsincotangqrl1234567890*/+-\n ";
    if (strlen(formula) == 1) {
        flag = 0;
    }
    for (int i = 0; flag && formula[i] != '\0'; i++) {
        if (formula[i] == ' ')
            count_space++;
        else if (formula[i] == '(')
            open_bracket++;
        else if (formula[i] == ')')
            close_bracket++;
        else if (strchr(valid_symbols, formula[i]) != NULL)
            continue;
        else
            flag = 0;
    }

    if (flag) {
        if (count_space == (int)strlen(formula) - 1) flag = 0;
        if (open_bracket != close_bracket) flag = 0;
    }
    return flag;
}