#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isExpression(char *line);

bool isValid(char c);

int main() {
    printf("Enter buffer length:\n");
    int n;
    scanf("%d", &n);

    printf("Enter line:\n");
    char *line = calloc(n + 1, sizeof(char));
    scanf("%s", line);

    if(isExpression(line)) {
        printf("Line is expression.\n");
    } else {
        printf("Line is not expression.\n");
    }

    free(line);
    return 0;
}

bool isExpression(char *line) {
    int i = 0;
    while (line[i] > 0) {
        if (!isValid(line[i])) return false;
        i++;
    }
    return true;
}


bool isValid(char c) {
    if(c >= '0' && c <= '9') return true;

    switch (c) {
        case '+':
        case '*':
        case '-':
        case '/':
        case ' ':
            return true;
        default:
            return false;
    }
}

/*
2) Проверить, является ли строка выражением (состоит из целых цифр, знаков операций и пробелов)
*/