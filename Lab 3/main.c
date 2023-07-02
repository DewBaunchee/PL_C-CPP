#include <stdio.h>
#include <string.h>

char text;

void inputText() {
    puts("Enter text:");
    fflush(stdin);
    gets(&text);
}

char * printLongestWord(char * str) {
    str[strlen(str)] = ' ';
    int max = 0, begin = 0, end = 0;
    int maxBegin = 0, maxEnd = 0;
    char wordBegan = 0;

    for(int i = 0; i < strlen(str); i++) {
        if (wordBegan) {
            if(str[i] == ' ') {
                wordBegan = 0;
                end = i;
                if(max < end - begin) {
                    max = end - begin;
                    maxBegin = begin;
                    maxEnd = end;
                }
            }
        } else {
            if (str[i] != ' ') {
                begin = i;
                wordBegan = 1;
            }
        }
    }

    for (int i = maxBegin; i < maxEnd; i++) {
        putchar(str[i]);
    }
}

int main() {
    inputText();
    printLongestWord(&text);
    return 0;
}