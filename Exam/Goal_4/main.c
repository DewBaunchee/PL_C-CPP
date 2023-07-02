#include <stdio.h>
#include <stdlib.h>

struct Matrix {
    int ** matrix;
    int rowCount, colCount;
};

void printMatrix(struct Matrix matrix);

int sumOfCol(struct Matrix matrix, int i);

void inputMatrix(struct Matrix *pMatrix);



int main() {
    struct Matrix matrix;
    inputMatrix(&matrix);

    if(matrix.rowCount == 0 || matrix.colCount == 0) return 1;

    int maxSum = sumOfCol(matrix, 0);
    int indexOfMax = 0;
    for(int i = 1; i < matrix.colCount; i++) {
        int temp = sumOfCol(matrix, i);
        if(temp >= maxSum) {
            maxSum = temp;
            indexOfMax = i;
        }
    }

    printf("Last col with max sum is #%d\n", indexOfMax);
    printMatrix(matrix);
    return 0;
}

void inputMatrix(struct Matrix *pMatrix) {
    printf("Enter N and M [N M]:\n");
    scanf("%d %d", &pMatrix->rowCount, &pMatrix->colCount);

    pMatrix->matrix = calloc(pMatrix->rowCount, sizeof (int));
    for(int i = 0; i < pMatrix->rowCount; i++) {
        printf("Row #%d:\n", i);
        pMatrix->matrix[i] = calloc(pMatrix->colCount, sizeof (int));
        for(int j = 0; j < pMatrix->colCount; j++) {
            printf("Cell #%d:\n", j);
            scanf("%d", &pMatrix->matrix[i][j]);
        }
        printf("\n");
    }
}

int sumOfCol(struct Matrix matrix, int col) {
    int sum = 0;
    for(int i = 0; i < matrix.rowCount; i++) {
        sum += matrix.matrix[i][col];
    }
    return sum;
}

/*
2 3
1
2
3
4
5
6

 */
void printMatrix(struct Matrix matrix) {
    for(int i = 0; i < matrix.rowCount; i++) {
        for(int j = 0; j < matrix.colCount; j++) {
            printf("%d ", matrix.matrix[i][j]);
        }
        printf("\n");
    }
}
/*

4) Ввести N и M. Потом вводим двумерный массив размера N, M. Найти и вывести номер последнего столбца сумма элементов
 которого максимальна.
 */