#pragma once

#include <math.h>
#include <stdio.h>
#define HEIGHT 25
#define WIDTH 80
#define Y_CENTER 12
#define X_MIN 0
#define PI 3.14159265358979323846
#define X_MAX (PI * 4)
#define Y_MIN -1
#define Y_MAX 1
#define STEP_X ((X_MAX - X_MIN) / (WIDTH - 1))

void build_matrix(char matrix[HEIGHT][WIDTH]);
void get_result(char matrix[HEIGHT][WIDTH], char *formula);
void output(char matrix[HEIGHT][WIDTH]);