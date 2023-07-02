#include <stdio.h>
#include <stdint.h>

int main() {
    printf("Enter N:\n");
    int n;
    scanf("%d", &n);

    if(n <= 0 || n % 2 == 1) return 1;

    int array[n];
    for(int i = 0; i < n; i++) {
        printf("Cell #%d:", i);
        fflush(stdin);
        scanf("%d", &array[i]);
    }

    int max = array[0] + array[1];
    int countOfMax = 1;
    for(int i = 2; i < n; i = i + 2) {
        int sum = array[i] + array[i + 1];
        if(sum == max) countOfMax++;
        if(max < sum) {
            max = sum;
            countOfMax = 1;
        }
    }

    printf("Max sum is %d (count is %d).\n", max, countOfMax);

    return 0;
}
/*Ввести n с клавиатуры, которое положительное и четное, потом ввести элементы массива размерности n
 * (элементы массива только целые числа). Сгруппировать 1 элемент со 2, 3 с 4, 5 с 6... .
 * За один проход массива найти максимальную сумму из групп элементов,
 * и количество максимальных сум(типо, если они повторяются) В первой строке вывести максимальную сумму,
 * во второй вывести количество максимальных сумм
 *
 * */