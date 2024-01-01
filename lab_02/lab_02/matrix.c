#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <errno.h>
#include "matrix.h"
#include "math.h"
#include <stdbool.h>

#define ERR_ALLOC_MEM "ERROR: couldn't allocate memory\nEXIT WITH ERROR CODE 1\n"

int** alloc2DArray(int height, int width) {
    int** arr = malloc(height * sizeof(int*));
    if (!arr) {
        printf_s(ERR_ALLOC_MEM);
        exit(1);
    }
    for (int i = 0; i < height; ++i) {
        if (!(arr[i] = malloc(width * sizeof(int)))) {
            for (int j = 0; j < i; ++j) {
                free(arr[j]);
            }
            free(arr);
            printf_s(ERR_ALLOC_MEM);
            exit(1);
        }
    }
    return arr;
}

void free2DArray(int** arr, int height) 
{
    for (int i = 0; i < height; ++i) 
    {
        free(arr[i]);
            }
    free(arr);
}

void SumMatrix(int height, int width, int height2, int width2, FILE* input1, FILE* input2, int** arr, int** arr2, int** arr3) 
{
    if (width != width2 || height != height2)
    {
        printf_s(" Invalid Matrix Size For This Operation! \n");
        exit(1);
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            fscanf_s(input1, "%d", &arr[i][j]);
        }
    }
    /// 
    for (int i = 0; i < height2; i++)
    {
        for (int j = 0; j < width2; j++)
        {
            fscanf_s(input2, "%d", &arr2[i][j]);
        }

    }
    printf_s("SUM Matrix:\n");
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            arr3[i][j] = arr2[i][j] + arr[i][j];
        }

    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            printf_s("%d ", arr3[i][j]);
        }
        printf_s("\n");
    }
}
void NegMatrix(int height, int width, int height2, int width2, FILE* input1, FILE* input2, int** arr, int** arr2, int** arr3)
{
    if (width != width2 || height != height2)
    {
        printf_s(" Invalid Matrix Size For This Operation! \n");
        exit(1);
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            fscanf_s(input1, "%d", &arr[i][j]);
        }
    }
    /// 
    for (int i = 0; i < height2; i++)
    {
        for (int j = 0; j < width2; j++)
        {
            fscanf_s(input2, "%d", &arr2[i][j]);
        }

    }
    printf_s("NEG Matrix:\n");
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            arr3[i][j] = arr[i][j] - arr2[i][j];
        }

    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            printf_s("%d ", arr3[i][j]);
        }
        printf_s("\n");
    }
}
void Transpose1(int height, int width, FILE* input1, FILE* input2, int** arr, int** arr2, int** arr3) 
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            fscanf_s(input1, "%d", &arr[i][j]);
        }
    }
    /// width * height
    printf_s("Tanspose of first Matrix:\n");
    int **arr4 = alloc2DArray(width, height);
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            arr4[i][j] = arr[j][i];
        }

    }
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            printf_s("%d ", arr4[i][j]);
        }
        printf_s("\n");
    }
    free2DArray(arr4, width);
}
void Transpose2(int height2, int width2, FILE* input1, FILE* input2, int** arr, int** arr2, int** arr3) 
{
    for (int i = 0; i < height2; i++)
    {
        for (int j = 0; j < width2; j++)
        {
            fscanf_s(input2, "%d", &arr2[i][j]);
        }

    }
    printf_s("Tanspose of second Matrix:\n");
    int** arr4 = alloc2DArray(width2, height2);
    for (int i = 0; i < width2; i++)
    {
        for (int j = 0; j < height2; j++)
        {
            arr4[i][j] = arr2[j][i];
        }

    }
    for (int i = 0; i < width2; i++)
    {
        for (int j = 0; j < height2; j++)
        {
            printf_s("%d ", arr4[i][j]);
        }
        printf_s("\n");
    }
    free2DArray(arr4, width2);
}

void MultMAtrix(int height, int width, int height2, int width2, FILE* input1, FILE* input2, int** arr, int** arr2)
{
    if (width != height2)
    {
        printf_s(" Invalid Matrix Size For This Operation! ");
        exit(1);
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            fscanf_s(input1, "%d", &arr[i][j]);
        }
    }
    /// 
    for (int i = 0; i < height2; i++)
    {
        for (int j = 0; j < width2; j++)
        {
            fscanf_s(input2, "%d", &arr2[i][j]);
        }

    }
    printf_s("MULTIPLICATION of Matrices:\n");
    int** arr3 = alloc2DArray(height, width2);
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width2; j++)
        {
            arr3[i][j] = 0;
            for (int n = 0; n < width; n++)
            {
                arr3[i][j] += arr[i][n] * arr2[n][j];
            }
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width2; j++)
        {
             printf_s("%d ", arr3[i][j]);
        }
        printf_s("\n");
    }
}


int ** matr(int ** a, int n, int x){
    int** res = (int**)malloc((n - 1) * sizeof(int*));
    for (int i = 0; i < n - 1; ++i)
        res[i] = (int *)malloc((n - 1) * sizeof(int));
    for (int i = 1; i < n; ++i)
        for (int j = 0, k = 0; j < n; ++j, ++k){
            if (j == x){
                --k;
                continue;
            }
            res[i - 1][k] = a[i][j];
        }
    return res;
}
// Function to get determinant of matrix
int determinantOfMatrix(int** a, int n, FILE* input1)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fscanf_s(input1, "%d", &a[i][j]);
        }
    }

    if (n == 1)
        return a[0][0];
    if (n == 2)
        return (a[1][1] * a[0][0]) - (a[0][1] * a[1][0]);
    int ans = 0, sig = 1;
    for (int i = 0; i < n; ++i) {
        ans += (sig * a[0][i] * determinantOfMatrix(matr(a, n, i), n - 1, input1));
        sig *= -1;
    }

    return ans;
}

bool next_permutation(int* array, int size) {
    int i = size - 1;
    while (i > 0 && array[i - 1] >= array[i]) {
        i--;
    }
    if (i <= 0) {
        return false;
    }

    int j = size - 1;
    while (array[j] <= array[i - 1]) {
        j--;
    }

    // Меняем элементы i-1 и j местами
    int temp = array[i - 1];
    array[i - 1] = array[j];
    array[j] = temp;

    // Разворачиваем оставшуюся часть массива
    j = size - 1;
    while (i < j) {
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
        i++;
        j--;
    }

    return true;
}

// Функция для создания подматрицы
int** createSubmatrix(int** matrix, int rows, int col1, int col2, int col3, int col4) {
    int** submatrix = (int**)malloc(4 * sizeof(int*));
    for (int i = 0; i < 4; ++i) {
        submatrix[i] = (int*)malloc(4 * sizeof(int));
        submatrix[i][0] = matrix[i][col1];
        submatrix[i][1] = matrix[i][col2];
        submatrix[i][2] = matrix[i][col3];
        submatrix[i][3] = matrix[i][col4];
    }

    return submatrix;
}

// Функция для вывода матрицы
void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Функция для освобождения памяти, выделенной под матрицу
void freeMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; ++i) {
        free(matrix[i]);
    }
    free(matrix);
}

// Основная функция для генерации и вывода всех перестановок
void permutation(int** arr, int height, FILE* input1) {
    int coo = 1;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            fscanf_s(input1, "%d", &arr[i][j]);
        }
    }
    int size = 5;
    int* colIndices = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; ++i) {
        colIndices[i] = i;
    }

    do {
        printf("Permutation %d:\n", coo);
        int** submatrix = createSubmatrix(arr, height, colIndices[0], colIndices[1], colIndices[2], colIndices[3]);
        printMatrix(submatrix, height, 4);

        int det = determinantOfMatrix(submatrix, 4, input1);

        printf("Determinant: %d\n", det);
        if (det== 0)
            exit(0);

        // Освобождение памяти под submatrix
        freeMatrix(submatrix, height);
        coo++;
    } while (next_permutation(colIndices, size));

    // Освобождение памяти
    free(colIndices);
}