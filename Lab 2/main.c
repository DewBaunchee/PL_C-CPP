#include <stdio.h>
#include <stdlib.h>

int n;
int **matrix;
int **finalMatrix;

struct Indexes {
    int i, j;
};

void inputElements(int n) {
    printf("Enter elements: \n");
    for(int i = 0; i < n; i++) {
        matrix[i] = calloc(n, sizeof(int));
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    finalMatrix = calloc(n - 1, sizeof(int));
    for(int i = 0; i < n; i++) {
        finalMatrix[i] = calloc(n - 1, sizeof(int));
    }
}

void randomizeElements(int n) {
    printf("Randomized elements: \n");
    srand(n * 20);
    for(int i = 0; i < n; i++) {
        matrix[i] = calloc(n, sizeof(int));
        for (int j = 0; j < n; j++) {
            matrix[i][j] = rand() % 1000 - 500;
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    finalMatrix = calloc(n - 1, sizeof(int));
    for(int i = 0; i < n; i++) {
        finalMatrix[i] = calloc(n - 1, sizeof(int));
    }
}

void inputMatrix() {
    char invalid = 1;
    do {
        printf("Enter size of matrix (0 < n < 11): \n");
        scanf("%d", &n);
        if (n > 0 && n < 11) {
            invalid = 0;
        }
    } while(invalid);
    matrix = calloc(n, sizeof(int));
    printf("Do you want to randomize elements? [y/n]\n");
    fflush(stdin);
    if(getchar() == 'y') {
        randomizeElements(n);
    } else {
        inputElements(n);
    }
}

struct Indexes findMin() {
    struct Indexes indexesOfMin;
    indexesOfMin.i = -1;
    indexesOfMin.j = -1;
    int min = 9999999;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(matrix[i][j] < min) {
                min = matrix[i][j];
                indexesOfMin.i = i;
                indexesOfMin.j = j;
            }
        }
    }
    return indexesOfMin;
}

void reformMatrix() {
    struct Indexes indexesOfMin = findMin();
    int i = 0, j = 0;
    int iMatrix = 0, jMatrix = 0;
    while(iMatrix < n) {
        jMatrix = 0;
        j = 0;
        if (iMatrix != indexesOfMin.i) {
            while (jMatrix < n) {
                if (jMatrix != indexesOfMin.j) {
                    finalMatrix[i][j] = matrix[iMatrix][jMatrix];
                    j++;
                }
                jMatrix++;
            }
            i++;
        }
        iMatrix++;
    }
}

void outputMatrix(int ** matr) {
    printf("Final matrix:\n");
    for(int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            printf("%d ", matr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    inputMatrix();
    reformMatrix();
    outputMatrix(finalMatrix);
    return 0;
}