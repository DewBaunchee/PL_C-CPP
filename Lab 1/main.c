#include <stdio.h>
#include <stdlib.h>

int n;
int * arr;

void inputNumbers() {
    char inValid = 1;
    do {
        printf("Enter number of natural numbers (0<n<16):\n");
        scanf("%d", &n);
        if (n > 0 && n < 16) {
            inValid = 0;
        }
    } while(inValid);
    arr = calloc(n, sizeof(int));
    printf("Enter numbers:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

int countA() {
    int counter = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] % 2 == 1) {
            counter++;
        }
    }
    return counter;
}

int countB() {
    int counter = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] % 3 == 0 && arr[i] % 5 != 0) {
            counter++;
        }
    }
    return counter;
}

int main() {
    inputNumbers();
    printf("Count of odd numbers: %d\n", countA());
    printf("Count of numbers multiple of 3 and non-multiple of 5: %d\n", countB());
    return 0;
}