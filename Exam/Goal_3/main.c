#include <stdio.h>
#include <stdlib.h>

void printArray(float *pDouble, int n);

int main() {
    while (1) {
        printf("Enter N:\n");
        int n;
        scanf("%d", &n);

        if(n < 1) break;

        float *array = calloc(n, sizeof(float));
        for (int i = 0; i < n; i++) {
            printf("Enter element #%d: \n", i);
            scanf("%f", &array[i]);
        }

        float temp = array[0];
        for (int i = 1; i < n; i++) {
            array[i - 1] = array[i];
        }
        array[n - 1] = temp;
        printArray(array, n);
    }
    return 0;
}

void printArray(float *array, int n) {
    printf("[ ");
    for(int i = 0; i < n - 1; i++) {
        printf("%5.1f, ", array[i]);
    }
    printf("%5.1f ]\n", array[n - 1]);
}
/*
3) Ввести N с клавиатуры. Ввести массив вещественных чисел размером N с клавиатуры.
 Циклически сдвинуть массив на 1 влево. Вывести массив на экран в одну строку, на каждый элемент 7 позиций
*/