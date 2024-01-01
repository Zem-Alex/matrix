#pragma once
#include <stdbool.h>

int** alloc2DArray(int height, int width);
void free2DArray(int** arr, int height);
void SumMatrix(int height, int width, int height2, int width2, FILE* input1, FILE* input2, int** arr, int** arr2, int** arr3);
void NegMatrix(int height, int width, int height2, int width2, FILE* input1, FILE* input2, int** arr, int** arr2, int** arr3);
void Transpose1(int height, int width, FILE* input1, FILE* input2, int** arr, int** arr2, int** arr3);
void Transpose2(int height2, int width2, FILE* input1, FILE* input2, int** arr, int** arr2, int** arr3);
void MultMAtrix(int height, int width, int height2, int width2, FILE* input1, FILE* input2, int** arr, int** arr2);
int** matr(int** a, int n, int x);
int determinantOfMatrix(int** a, int n, FILE* input1);
bool next_permutation(int* array, int size);
int** createSubmatrix(int** matrix, int rows, int col1, int col2, int col3, int col4);
void printMatrix(int** matrix, int rows, int cols);
void freeMatrix(int** matrix, int rows);
void permutation(int** arr, int height, FILE* input1);