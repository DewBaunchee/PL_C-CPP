#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isSawtooth(int * array, int n);

int main() {
    printf("Enter N:\n");
    int n;
    scanf("%d", &n);

    if(n < 1) return 1;

    int *array = calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) {
        printf("Enter element #%d: \n", i);
        scanf("%d", &array[i]);
    }

    if(isSawtooth(array, n)) {
        printf("YES");
    } else {
        printf("NO");
    }

    return 0;
}

bool isSawtooth(int * array, int n) {
    if(n == 1) return true;
    bool shouldBeBigger = array[0] <= array[1];
    for(int i = 2; i < n; i++) {
        if(shouldBeBigger) {
            if(array[i - 1] <= array[i]) return false;
            shouldBeBigger = !shouldBeBigger;
        } else {
            if(array[i - 1] >= array[i]) return false;
            shouldBeBigger = !shouldBeBigger;
        }
    }
    return true;
}
/*Дано число N, массив целочисленных чисел размером N(тут надо ввести число с клавы). Проверить, являются ли элементы в массиве в пилообразном порядке?
Примеры:
1) a1>a2<a3>a4<a5
2) a1<a2>a3<a4>a5
5
6
4
5
4
4

 */