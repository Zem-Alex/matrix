#pragma once

int** alloc2DArray(int height, int width);
void free2DArray(int** arr, int height);
void SumMatrix(int height, int width, int height2, int width2, FILE* input1, FILE* input2, int** arr, int** arr2, int** arr3);
void NegMatrix(int height, int width, int height2, int width2, FILE* input1, FILE* input2, int** arr, int** arr2, int** arr3);
void Transpose1(int height, int width, FILE* input1, FILE* input2, int** arr, int** arr2, int** arr3);
void Transpose2(int height2, int width2, FILE* input1, FILE* input2, int** arr, int** arr2, int** arr3);
void MultMAtrix(int height, int width, int height2, int width2, FILE* input1, FILE* input2, int** arr, int** arr2);
int** matr(int** a, int n, int x);
int determinantOfMatrix(int** a, int n, FILE* input1);
