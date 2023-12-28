#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <errno.h>
#include "matrix.h"
#include "math.h"
#include <stdbool.h>

#define ERR_ALLOC_MEM "ERROR: couldn't allocate memory\nEXIT WITH ERROR CODE 1\n"

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

        // Освобождение памяти под submatrix
        freeMatrix(submatrix, height);
        coo++;
    } while (next_permutation(colIndices, size));

    // Освобождение памяти
    free(colIndices);
}



int main(void) {
    FILE* input1 = 0, * input2 = 0, * output = 0;
    //
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
        if (longn > 2147483647) {
            return 3;
        }
    }
    _fcloseall();
    //printf_s("\n%lld\n", longn);
    if (fopen_s(&input1, "i1.txt", "r") || fopen_s(&input2, "i2.txt", "r"))
    {
        perror("");
        _fcloseall();
        exit(1);
    }
    while (fscanf_s(input1, "%c", &SYMBOL, 1) != EOF) {
        if (SYMBOL == ' ') 
        {
            probel++;
        }
        if (SYMBOL == '\n')
        {
            enter++;
        }
        if (((SYMBOL < '0') || (SYMBOL > '9')) && (SYMBOL != '-') && (SYMBOL != ' ') && (SYMBOL != '\n'))
        {
            flag++;
            if (count > 10) {
                max = 1;
            }
            count = 0;
        }
        if ((SYMBOL >= '0') && (SYMBOL <= '9'))
        {
            count++;
            if (count > 10) {
                max = 1;
            }
        }
        else
        {
            if (count > 10) {
                max = 1;
            }
            count = 0;
        }
    }
    int width, height;
    height = enter + 1;
    width = (probel + height) / height;
    /// 
    int probel2 = 0, enter2 = 0;
    char SYMBOL2 = 0;
    count = 0;
    while (fscanf_s(input2, "%c", &SYMBOL2, 1) != EOF) {
        if (SYMBOL2 == ' ')
        {
            probel2++;
        }
        if (SYMBOL2 == '\n')
        {
            enter2++;
        }
        if (((SYMBOL2 < '0') || (SYMBOL2 > '9')) && (SYMBOL2 != '-') && (SYMBOL2 != ' ') && (SYMBOL2 != '\n'))
        {
            flag++;
            if (count > 10) {
                max = 1;
            }
            count = 0;
        }
        if ((SYMBOL2 >= '0') && (SYMBOL2 <= '9'))
        {
            count++;
            if (count > 10) {
                max = 1;
            }
        }
        else
        {
            if (count > 10) {
                max = 1;
            }
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
    //printf_s("\nInvalidishe  %d %d \n", count, max);
    int width2, height2;
    height2 = enter2 + 1;
    width2 = (probel2 + height2) / height2;
    _fcloseall();
    /// 
    if (fopen_s(&input1, "i1.txt", "r") || fopen_s(&input2, "i2.txt", "r"))
    {
        perror("");
        _fcloseall();
        exit(1);
    }
    printf_s("Size of 1 Matrix: %d * %d\nSize of 2 matrix: %d * %d\n\n", width, height, width2, height2);
    /// 
    int** arr = alloc2DArray(height, width), ** arr2 = alloc2DArray(height, width), ** arr3 = alloc2DArray(height, width);
    int det = -1;
    /// 
    printf_s("Select operation on Matrix:\n1) Matrix addition\n2) Matrix negation\n3) Transpose the first matrix\n4) Transpose the second matrix\n5) Matrix multiplication\n6) Matrix determination\n7) Matrix permutation\n");
    int value = 0;
   
    scanf_s("%d", &value);
    switch (value) 
    {
    case 1:
        SumMatrix(height, width, height2, width2, input1, input2, arr, arr2, arr3);
        break;
    case 2:
        NegMatrix(height, width, height2, width2, input1, input2, arr, arr2, arr3);
        break;
    case 3: 
        Transpose1(height, width, input1, input2, arr, arr2, arr3);
        break;
    case 4:
        Transpose2(height2, width2, input1, input2, arr, arr2, arr3);
        break;
    case 5:
        MultMAtrix(height, width, height2, width2, input1, input2, arr, arr2);
        break;
    case 6:
        det = determinantOfMatrix(arr, height, input1);
        printf_s("Det = %i", det);
        break;
    case 7:
        permutation(arr, height, input1);
        break;
    default:
        printf_s("Inknown operation");
        break;
    }

    free2DArray(arr, height);
    //free2DArray(arr2, height2);
    free2DArray(arr3, height);
	return 0;
}