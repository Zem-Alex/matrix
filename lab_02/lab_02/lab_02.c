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
        if (longn > 2147483647) 
            return 3;
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