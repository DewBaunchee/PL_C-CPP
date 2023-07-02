#include <stdio.h>
#include <stdlib.h>

struct Digit {
    char digit;
    struct Digit *next;
};

void printNumber(struct Digit *pDigit);

int main() {
    printf("Enter A and D\n");
    int a, d;
    scanf("%d %d", &a, &d);

    if(d < 1 || d > 9) return 1;

    struct Digit* number = 0;
    while(a > 0) {
        int temp = a % d;
        struct Digit *new = calloc(1, sizeof (struct Digit));
        new->digit = temp + '0';
        new->next = number;
        number = new;
        a = (a - temp) / d;
    }

    printNumber(number);
    return 0;
}

void printNumber(struct Digit *pDigit) {
    if(!pDigit) {
        printf("Not a number.");
    } else {
        while (pDigit != 0) {
            printf("%c", pDigit->digit);
            pDigit = pDigit->next;
        }
    }
}
/*
 * Вводятся 2 целочисленные переменные А и D, (2<=D<=9), записать А в системе D ( типа А в D-ичной системе),
 * конечная строка не должна содержать лишних нулей
 * */
