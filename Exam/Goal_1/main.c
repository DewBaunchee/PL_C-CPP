#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void task1(char *line);

void task2_1(char *line);

void task2_2(char *line);

void task3(char *line);

int main() {
    printf("Enter buffer length:\n");
    int n;
    scanf("%d", &n);

    printf("Enter line:\n");
    char *line = calloc(n + 1, sizeof(char));
    scanf("%s\n", line);
    printf("Enter task:\n");

    switch (getchar()) {
        case '1':
            getchar();
            task1(line);
            break;
        case '2':
            getchar();
            task2_1(line);
            break;
        case '3':
            getchar();
            task2_2(line);
            break;
        case '4':
            getchar();
            task3(line);
            break;
    }

    free(line);
    return 0;
}

void task1(char *line) {
    printf("Enter symbol:\n");
    getchar();
    unsigned char c = getchar();

    int length = strlen(line);
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (line[i] == c) count++;
    }
    printf("Percentage of '%c' in line: %f%%", c, (float) count * 100 / (float) length);
}

void task2_1(char *line) {
    // удаление элементов равных k
    printf("Deleting k in array. Enter k: \n");
    unsigned char k = getchar();

    unsigned int i = 0;
    unsigned int offset = 0;
    while (line[i] > 0) {
        line[i - offset] = line[i];
        if (line[i] == k) {
            offset++;
        }
        i++;
    }
    line[i - offset] = line[i];
    printf("Result: %s", line);
/*
123
12345676234435456243
2

 */
}

void task2_2(char *line) {
    // удаление первые k элементов
    printf("Deleting k elements in array. Enter k: \n");
    unsigned int k;
    scanf("%d", &k);

    if (k < 1 || k > strlen(line)) {
        printf("VRONG");
        return;
    }

    unsigned int i = 0;
    while (line[i + k] > 0) {
        line[i] = line[i + k];
        i++;
    }
    line[i] = line[i + k];
    printf("Result: %s", line);
/*
123
12345676234435456243
3

 */
}

void task3(char *line) {
// найти всё вхождения символа в строку и сформировать новую из тех, которая без этого символа
    printf("Deleting k in array. Enter k: \n");
    unsigned char k = getchar();

    unsigned int i = 0;
    unsigned int offset = 0;
    while (line[i] > 0) {
        line[i - offset] = line[i];
        if (line[i] == k) {
            printf("'%c' on position #%d\n", k, i);
            offset++;
        }
        i++;
    }
    line[i - offset] = line[i];
    printf("Result: %s", line);
/*
123
12345676234435456243
4

 */
}

/*
1) Найти процентное отношение в строке символа, введённого с клавиатуры; удалить k-элемент из массива;
 найти всё вхождения символа в строку и сформировать новую из тех, которая без этого символа
 */