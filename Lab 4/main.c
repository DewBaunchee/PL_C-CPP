#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    char author[20];
    char name[20];
    int year;
};

struct Book * bookList;
struct Book * customList;
int n;

void inputBookList() {
    puts("Enter path to file:");
    char *fileName;
    gets(fileName);
    FILE * opFile = fopen(fileName, "r");
    fscanf(opFile, "%d", &n);
    bookList = calloc(n, sizeof(struct Book));
    for(int i = 0; i < n; i++) {
        fscanf(opFile, "%s %s %d", bookList[i].author, bookList[i].name, &bookList[i].year);
    }
}

char firstBiggerThanSecond(char * s1, char * s2) {
    unsigned int mainLen = 0;
    if (strlen(s1) > strlen(s2)) {
        mainLen = strlen(s2);
    } else {
        mainLen = strlen(s1);
    }
    for(int i = 0; i < mainLen; i++) {
        if(s1[i] > s2[i]) {
            return 1;
        } else {
            if(s1[i] < s2[i]) {
                return 0;
            }
        }
    }
}

void outputInAlphabetOrder(struct Book * list, int count) {
    for(int i = 0; i < count; i++) {
        for(int j = count - 1; j > i; j--) {
            if (firstBiggerThanSecond(list[j - 1].author, list[j].author)) {
                struct Book book = list[j - 1];
                list[j - 1] = list[j];
                list[j] = book;
            }
        }
    }
    for(int i = 0; i < count; i++) {
        printf("%s %s %d\n", customList[i].author, customList[i].name, customList[i].year);
    }
}

void outputCustomList() {
    int counter = 0;
    for(int i = 0; i < n; i++) {
        if (bookList[i].year > 2000) {
            counter++;
        }
    }
    customList = calloc(counter, sizeof(struct Book));
    int j = 0;
    for(int i = 0; i < n; i++) {
        if (bookList[i].year > 2000) {
            customList[j] = bookList[i];
            j++;
        }
    }
    outputInAlphabetOrder(customList, counter);
}

int main() {
    inputBookList();
    outputCustomList();
    return 0;
}