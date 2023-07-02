#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findSymbolAfter(char *line, int start, char symbol);

void deleteInLine(char *line, int i, int comment);

int main() {
    printf("Enter buffer length:\n");
    int n;
    scanf("%d", &n);

    printf("Enter line:\n");
    char *line = calloc(n + 1, sizeof(char));
    getchar();
    char c;
    int index = 0;
    while((c = (char) getchar()) != '\n') {
        line[index++] = c;
    }
    line[index] = 0;

    for(int i = 0; i < strlen(line); i++) {
        if(line[i] == '"') {
            int closeQuote = findSymbolAfter(line, i + 1, '"');
            i = closeQuote;
            continue;
        }
        if(line[i] == '{') {
            int closeComment = findSymbolAfter(line, i + 1, '}');
            deleteInLine(line, i, closeComment + 1);
            i--;
        }
    }

    printf("%s\n", line);
    return 0;
}

void deleteInLine(char *line, int start, int end) {
    if(start > end || start < 0 || start >= strlen(line) || end < 0 || end > strlen(line)) return;
    int i = end;
    int offset = end - start;
    while (line[i] > 0) {
        line[i - offset] = line[i];
        i++;
    }
    line[i - offset] = line[i];
}

int findSymbolAfter(char *line, int start, char symbol) {
    while(line[start] != symbol) start++;
    return start;
}
/*

5) Ввести строку S. В строке S могут быть комментарии({коммент"ар"ий}), строковые литералы("лите{ра}л")
 и другие символы. Удалить из строки S все комментарии.

123
 "{asd}" {bcvb} "asd"

 */