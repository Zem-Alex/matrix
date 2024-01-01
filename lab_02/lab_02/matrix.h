#pragma once
#include <stdbool.h>

void printMatrix(int** matrix, int rows, int cols);
void scanMatrix(int** matrix, int rows, int cols, FILE* file);
int** alloc2DArray(int height, int width);
void free2DArray(int** arr, int height);
int SumMatrix(int height, int width, int height2, int width2, FILE* input1, FILE* input2, int** arr, int** arr2, int** arr3);
int NegMatrix(int height, int width, int height2, int width2, FILE* input1, FILE* input2, int** arr, int** arr2, int** arr3);
int Transpose(int height, int width, FILE* file, int** arr, int** out);
int MultMAtrix(int height, int width, int height2, int width2, FILE* input1, FILE* input2, int** arr, int** arr2, int** arr3);
int** matr(int** a, int n, int x);
int determinantOfMatrix(int** a, int n, FILE* input1);
bool next_permutation(int* array, int size);
int** createSubmatrix(int** matrix, int rows, int col1, int col2, int col3, int col4);
void freeMatrix(int** matrix, int rows);
void permutation(int** arr, int height, FILE* input1);
void matrixSizeFromFiles(int* height, int* width, int* height2, int* width2, FILE* input1, FILE* input2);
