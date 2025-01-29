#include "graphic.h"

#include "calculation.h"
#include "parsing.h"

void build_matrix(char matrix[HEIGHT][WIDTH]) {
    for (int row = 0; row < HEIGHT; row++) {
        for (int col = 0; col < WIDTH; col++) {
            matrix[row][col] = '.';
        }
    }
}

void get_result(char matrix[HEIGHT][WIDTH], char *formula) {
    int x_center = 0;
    for (double x = X_MIN; x_center < WIDTH; x += STEP_X) {
        char string_x[32];
        char math_expression[256];
        sprintf(string_x, "%lf", x);
        replace_x(math_expression, formula, string_x);
        double res = calculate_formula(math_expression);
        if ((res >= Y_MIN) && (res <= Y_MAX)) {
            int y = round(res * Y_CENTER);
            matrix[Y_CENTER + y][x_center] = '*';
        }
        x_center++;
    }
}

void output(char matrix[HEIGHT][WIDTH]) {
    for (int row = 0; row < HEIGHT; row++) {
        for (int col = 0; col < WIDTH; col++) {
            if (col == WIDTH - 1)
                printf("%c\n", matrix[row][col]);
            else
                printf("%c", matrix[row][col]);
        }
    }
}