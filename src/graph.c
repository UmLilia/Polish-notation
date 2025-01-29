#include <stdio.h>
#include <string.h>

#include "calculation.h"
#include "graphic.h"
#include "parsing.h"

int main() {
    char formula[256];
    fgets(formula, 256, stdin);
    if (check_valid(formula)) {
        char matrix[HEIGHT][WIDTH];
        build_matrix(matrix);
        get_result(matrix, formula);
        output(matrix);
    } else {
        printf("n/a");
    }
    return 0;
}