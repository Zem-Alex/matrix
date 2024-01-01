#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <errno.h>
#include "matrix.h"
#include "math.h"
#include <stdbool.h>
#include <time.h>

#define ERR_ALLOC_MEM "ERROR: couldn't allocate memory\nEXIT WITH ERROR CODE 1\n"

int main(void) 
{
    FILE* input1 = 0, * input2 = 0, * output = 0;
    int width = 0, height = 0, width2 = 0, height2;
    
   
    matrixSizeFromFiles(&height, &width, &height2, &width2, input1, input2);
    printf_s("Size of 1 Matrix: %d * %d\nSize of 2 matrix: %d * %d\n\n", width, height, width2, height2);

    int** arr = alloc2DArray(height, width), ** arr2 = alloc2DArray(height, width), ** arr3 = alloc2DArray(height, width);
    int det = -1;
    
    if (fopen_s(&input1, "i1.txt", "r") || fopen_s(&input2, "i2.txt", "r"))
    {
        perror("");
        _fcloseall();
        exit(1);
    }

    printf_s("First matrix:\n");
    scanMatrix(arr, height, width, input1);
    printMatrix(arr, height, width);
    printf_s("Second matrix: \n");
    scanMatrix(arr2, height2, width2, input2);
    printMatrix(arr2, height2, width2);
    int value = -1;

    while (value)
    {
        printf_s("Select operation on Matrix:\n1) Matrix addition\n2) Matrix negation\n3) Transpose the first matrix\n4) Transpose the second matrix\n5) Matrix multiplication\n6) Matrix determination\n0) Exit\n\n>");
   
        clock_t start, end;
        double cpu_time_used;
    
        scanf_s("%d", &value);
        printf_s("\n");

        switch (value) 
        {
        case 0:
            printf_s("Exit\n");
            break;
        case 1:
            if (SumMatrix(height, width, height2, width2, input1, input2, arr, arr2, arr3))
            {
                printf_s("SUM Matrix:\n");
                printMatrix(arr3, height, width);
            }
            break;
        case 2:
            if (NegMatrix(height, width, height2, width2, input1, input2, arr, arr2, arr3))
            {
                printf_s("NEG Matrix:\n");
                printMatrix(arr3, height, width);
            }
            break;
        case 3: 
            arr3 = alloc2DArray(width, height);
            if (Transpose(height, width, input1, arr, arr3))
            {
                printf_s("Tanspose of first Matrix:\n");
                printMatrix(arr3, width, height);
            }
            break;
        case 4:
            arr3 = alloc2DArray(width2, height2);
            if (Transpose(height2, width2, input2, arr2, arr3))
            {
                printf_s("Tanspose of first Matrix:\n");
                printMatrix(arr3, width2, height2);
            }
            break;
        case 5:
            arr3 = alloc2DArray(height, width2);
            if (MultMAtrix(height, width, height2, width2, input1, input2, arr, arr2, arr3))
            {
                printf_s("MULTIPLICATION of Matrices:\n");
                printMatrix(arr3, height, width2);
            }
            break;
        case 6:
            start = clock(); // Получаем время начала выполнения функции

            det = determinantOfMatrix(arr, height, input1);
            printf_s("Det = %i\n", det);

            end = clock(); // Получаем время окончания выполнения функции
            cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC; // Вычисляем время в секундах
            printf("Function execution time: %lf sec\n", cpu_time_used);

            break;
        case 7:
            permutation(arr, height, input1);
            break;
        default:
            printf_s("Inknown operation\n\n");
            break;
        }
    }
    free2DArray(arr, height);
    free2DArray(arr2, height2);
    if (value == 3)
        free2DArray(arr3, width);
    else if (value == 4)
        free2DArray(arr3, width2);
    else 
        free2DArray(arr3, height);
	return 0;
}