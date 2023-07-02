#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * string;

void randomizeString() {
    printf("Enter string length:\n");
    int n;
    scanf("%d", &n);
    srand(n * 20);
    string = calloc(n + 1, sizeof(char));
    for(int i = 0; i < n; i++) {
        string[i] = (char) rand();
    }
    string[n] = '\0';
    puts("Entered string:");
    puts(string);
}

void inputString() {
    puts("Enter string:");
    fflush(stdin);
    gets(string);
}

void input() {
    char invalid = 1;
    do {
        printf("Do you want to randomize string? [y/n]\n");
        switch (getchar()) {
            case 'y':
                randomizeString();
                invalid = 0;
                break;
            case 'n':
                inputString();
                invalid = 0;
                break;
        }
    }
    while (invalid);
}

void outputWithoutDigits(char * str) {
    puts("String without digits:");
    for(int i = 0; i < strlen(str); i++) {
        if(str[i] < (int) '0' || str[i] > (int) '9') {
            putchar(str[i]);
        }
    }
}

void checkString(char * str) {
    if (strlen(str) > 10) {
        outputWithoutDigits(str);
    }
}

int main() {
    input();
    checkString(string);
    return 0;
}