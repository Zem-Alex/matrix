#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <errno.h>
#include "matrix.h"
#include "math.h"
#include <stdbool.h>

#define ERR_ALLOC_MEM "ERROR: couldn't allocate memory\nEXIT WITH ERROR CODE 1\n"

int main(void) 
{
    FILE* input1 = 0, * input2 = 0, * output = 0;
    int width, height, width2, height2;
    
   
    matrixSizeFromFiles(&height, &width, &height2, &width2, input1, input2);
    printf_s("Size of 1 Matrix: %d * %d\nSize of 2 matrix: %d * %d\n\n", width, height, width2, height2);

    int** arr = alloc2DArray(height, width), ** arr2 = alloc2DArray(height, width), ** arr3 = alloc2DArray(height, width);
    int det = -1;
    
    printf_s("Select operation on Matrix:\n1) Matrix addition\n2) Matrix negation\n3) Transpose the first matrix\n4) Transpose the second matrix\n5) Matrix multiplication\n6) Matrix determination\n7) Matrix permutation\n");
    int value = 0;
   
    if (fopen_s(&input1, "i1.txt", "r") || fopen_s(&input2, "i2.txt", "r"))
    {
        perror("");
        _fcloseall();
        exit(1);
    }

    scanMatrix(arr, height, width, input1);
    scanMatrix(arr2, height2, width2, input2);

    scanf_s("%d", &value);
    switch (value) 
    {
    case 1:
        SumMatrix(height, width, height2, width2, input1, input2, arr, arr2, arr3);
        printf_s("SUM Matrix:\n");
        printMatrix(arr3, height, width);
        break;
    case 2:
        NegMatrix(height, width, height2, width2, input1, input2, arr, arr2, arr3);
        printf_s("NEG Matrix:\n");
        printMatrix(arr3, height, width);
        break;
    case 3: 
        Transpose(height, width, input1, arr, arr3);
        printf_s("Tanspose of first Matrix:\n");
        printMatrix(arr3, height, width);
        break;
    case 4:
        Transpose(height2, width2, input2, arr2, arr3);
        printf_s("Tanspose of first Matrix:\n");
        printMatrix(arr3, height2, width2);
        break;
    case 5:
        arr3 = alloc2DArray(height, width2);
        MultMAtrix(height, width, height2, width2, input1, input2, arr, arr2, arr3);
        printf_s("MULTIPLICATION of Matrices:\n");
        printMatrix(arr3, height, width2);
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
    free2DArray(arr2, height2);
    free2DArray(arr3, height);

	return 0;
}