#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Matrix {
    int ** matrix;
    int rowCount, colCount;
};

void printMatrix(struct Matrix matrix);

bool hasInRow(struct Matrix matrix, int row, int findable);

void inputMatrix(struct Matrix *pMatrix);

int main() {
    struct Matrix matrix;
    inputMatrix(&matrix);
    printf("Enter A:\n");
    int a;
    scanf("%d", &a);

    if(matrix.rowCount == 0 || matrix.colCount == 0) return 1;

    int count = 0;
    for(int i = 0; i < matrix.rowCount; i++) {
        if(hasInRow(matrix, i, a)) count++;
    }

    printf("Count of row with %d is %d\n", a, count);
    printMatrix(matrix);
    return 0;
}
/*
7 2
1
1
2
3
4
5
1
6
7
1
1
6
6
3
1

6 2
1
1
2
3
4
5
1
6
1
2
1
2
1

 */

void inputMatrix(struct Matrix *pMatrix) {
    printf("Enter N and M [N M]:\n");
    scanf("%d %d", &pMatrix->rowCount, &pMatrix->colCount);

    pMatrix->matrix = calloc(pMatrix->rowCount, sizeof (int*));
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

bool hasInRow(struct Matrix matrix, int row, int findable) {
    for(int i = 0; i < matrix.colCount; i++) {
        if(findable == matrix.matrix[row][i]) return true;
    }
    return false;
}

void printMatrix(struct Matrix matrix) {
    for(int i = 0; i < matrix.rowCount; i++) {
        for(int j = 0; j < matrix.colCount; j++) {
            printf("%d ", matrix.matrix[i][j]);
        }
        printf("\n");
    }
}