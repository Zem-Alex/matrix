#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <errno.h>
#include "matrix.h"
#include "math.h"
#include <stdbool.h>

#define ERR_ALLOC_MEM "ERROR: couldn't allocate memory\nEXIT WITH ERROR CODE 1\n"

// ������� ��� ������ �������
void printMatrix(int** matrix, int rows, int cols) 
{
    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < cols; ++j) 
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// ������� ��� ����� �������
void scanMatrix(int** matrix, int rows, int cols, FILE* file) 
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            fscanf_s(file, "%d", &matrix[i][j]);
        }
    }
}

int** alloc2DArray(int height, int width) 
{
    int** arr = malloc(height * sizeof(int*));

    if (!arr) 
    {
        printf_s(ERR_ALLOC_MEM);
        exit(1);
    }

    for (int i = 0; i < height; ++i) 
    {
        if (!(arr[i] = malloc(width * sizeof(int)))) 
        {
            for (int j = 0; j < i; ++j) 
            {
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

int SumMatrix(int height, int width, int height2, int width2, FILE* input1, FILE* input2, int** arr, int** arr2, int** arr3) 
{
    if (width != width2 || height != height2)
    {
        printf_s(" Invalid Matrix Size For This Operation! \n\n");
        return 0;
    }

    scanMatrix(arr, height, width, input1);
    scanMatrix(arr2, height2, width2, input2);
        
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            arr3[i][j] = arr2[i][j] + arr[i][j];

    return 1;
}
int NegMatrix(int height, int width, int height2, int width2, FILE* input1, FILE* input2, int** arr, int** arr2, int** arr3)
{
    if (width != width2 || height != height2)
    {
        printf_s(" Invalid Matrix Size For This Operation! \n\n");
        return 0;
    }

    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            arr3[i][j] = arr[i][j] - arr2[i][j];

    return 1;
}

int Transpose(int height, int width, FILE* file, int** arr, int** out)
{

    for (int i = 0; i < width; i++)
        for (int j = 0; j < height; j++)
            out[i][j] = arr[j][i];

    return 1;
}

int MultMAtrix(int height, int width, int height2, int width2, FILE* input1, FILE* input2, int** arr, int** arr2, int** arr3)
{
    if (width != height2)
    {
        printf_s(" Invalid Matrix Size For This Operation! \n\n");
        return 0;
    }

    for (int i = 0; i < height; i++)
        for (int j = 0; j < width2; j++)
        {
            arr3[i][j] = 0;
            for (int n = 0; n < width; n++)
                arr3[i][j] += arr[i][n] * arr2[n][j];
        }

    return 1;
}


int ** matr(int ** a, int n, int x)
{
    int** res = (int**)malloc((n - 1) * sizeof(int*));
    for (int i = 0; i < n - 1; ++i)
        res[i] = (int*)malloc((n - 1) * sizeof(int));
    for (int i = 1; i < n; ++i)
        for (int j = 0, k = 0; j < n; ++j, ++k){
            if (j == x){
                --k;
                continue;
            }
            res[i-1][k] = a[i][j];
        }
    return res;
}
// Function to get determinant of matrix
int determinantOfMatrix(int** a, int n, FILE* input1)
{
    scanMatrix(a, n, n, input1);

    if (n == 1)
        return a[0][0];
    if (n == 2)
        return (a[1][1] * a[0][0]) - (a[0][1] * a[1][0]);

    int ans = 0, sig = 1;

    for (int i = 0; i < n; ++i) 
    {
        ans += (sig * a[0][i] * determinantOfMatrix(matr(a, n, i), n - 1, input1));
        sig *= -1;
    }

    return ans;
}

bool next_permutation(int* array, int size) 
{
    int i = size - 1;
    while (i > 0 && array[i - 1] >= array[i]) 
    {
        i--;
    }

    if (i <= 0) 
        return false;

    int j = size - 1;
    while (array[j] <= array[i - 1]) 
    {
        j--;
    }

    // ������ �������� i-1 � j �������
    int temp = array[i - 1];
    array[i - 1] = array[j];
    array[j] = temp;

    // ������������� ���������� ����� �������
    j = size - 1;
    while (i < j) 
    {
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
        i++;
        j--;
    }

    return true;
}

// ������� ��� �������� ����������
int** createSubmatrix(int** matrix, int rows, int col1, int col2, int col3, int col4) 
{
    int** submatrix = (int**)malloc(4 * sizeof(int*));

    for (int i = 0; i < 4; ++i) 
    {
        submatrix[i] = (int*)malloc(4 * sizeof(int));
        submatrix[i][0] = matrix[i][col1];
        submatrix[i][1] = matrix[i][col2];
        submatrix[i][2] = matrix[i][col3];
        submatrix[i][3] = matrix[i][col4];
    }

    return submatrix;
}


// ������� ��� ������������ ������, ���������� ��� �������
void freeMatrix(int** matrix, int rows) 
{
    for (int i = 0; i < rows; ++i) {
        free(matrix[i]);
    }
    free(matrix);
}

// �������� ������� ��� ��������� � ������ ���� ������������
void permutation(int** arr, int height, FILE* input1) 
{
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

    for (int i = 0; i < size; ++i) 
    {
        colIndices[i] = i;
    }

    do 
    {
        printf("Permutation %d:\n", coo);
        int** submatrix = createSubmatrix(arr, height, colIndices[0], colIndices[1], colIndices[2], colIndices[3]);
        printMatrix(submatrix, height, 4);

        int det = determinantOfMatrix(submatrix, 4, input1);

        printf("Determinant: %d\n", det);
        if (det== 0)
            exit(0);

        freeMatrix(submatrix, height); // ������������ ������ ��� submatrix
        coo++;
    } while (next_permutation(colIndices, size));

    free(colIndices); // ������������ ������
}

void matrixSizeFromFiles(int* height, int* width, int* height2, int* width2, FILE* input1, FILE* input2)
{
    if (fopen_s(&input1, "i1.txt", "r") || fopen_s(&input2, "i2.txt", "r"))
    {
        perror("");
        _fcloseall();
        exit(1);
    }

    int probel = 0, enter = 0, flag = 0, max = 0, count = 0;
    char SYMBOL = 0;
    long long longn = 0;
    while (fscanf_s(input2, "%lld", &longn) != EOF)
    {
        if (longn > INT_MAX)
            return 3;
    }

    _fcloseall();

    if (fopen_s(&input1, "i1.txt", "r") || fopen_s(&input2, "i2.txt", "r"))
    {
        perror("");
        _fcloseall();
        exit(1);
    }

    while (fscanf_s(input1, "%c", &SYMBOL, 1) != EOF)
    {
        if (SYMBOL == ' ')
            probel++;
        if (SYMBOL == '\n')
            enter++;
        if (((SYMBOL < '0') || (SYMBOL > '9')) && (SYMBOL != '-') && (SYMBOL != ' ') && (SYMBOL != '\n'))
        {
            flag++;
            if (count > 10)
                max = 1;
            count = 0;
        }
        if ((SYMBOL >= '0') && (SYMBOL <= '9'))
        {
            count++;
            if (count > 10)
                max = 1;
        }
        else
        {
            if (count > 10)
                max = 1;
            count = 0;
        }
    }
    *height = enter + 1;
    *width = (probel + (*height)) / (*height);
    /// 
    int probel2 = 0, enter2 = 0;
    flag = 0; max = 0; count = 0;
    char SYMBOL2 = 0;

    while (fscanf_s(input2, "%c", &SYMBOL2, 1) != EOF)
    {
        if (SYMBOL2 == ' ')
            probel2++;
        if (SYMBOL2 == '\n')
            enter2++;
        if (((SYMBOL2 < '0') || (SYMBOL2 > '9')) && (SYMBOL2 != '-') && (SYMBOL2 != ' ') && (SYMBOL2 != '\n'))
        {
            flag++;
            if (count > 10)
                max = 1;
            count = 0;
        }
        if ((SYMBOL2 >= '0') && (SYMBOL2 <= '9'))
        {
            count++;
            if (count > 10)
                max = 1;
        }
        else
        {
            if (count > 10)
                max = 1;
            count = 0;
        }
    }
    if (flag > NULL) {
        printf_s("\nInvalid elements! %d unknown elements\n", flag);
        return 1;
    }
    if (max == 1) {
        printf_s("\nInvalid size of elements! \n");
        return 1;
    }

    *height2 = enter2 + 1;
    *width2 = (probel2 + (*height2)) / (*height2);
    _fcloseall();

}