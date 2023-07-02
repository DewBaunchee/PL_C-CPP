#include <stdio.h>
#include <string.h>

FILE * inputFileName() {
    char fileName;
    puts("Enter input filename:");
    scanf("%s", &fileName);
    return fopen(&fileName, "r");
}

FILE * outputFileName() {
    char fileName;
    puts("Enter output filename:");
    scanf("%s", &fileName);
    return fopen(&fileName, "w");
}

void copyWithoutColonAndExclamation(FILE * inFile, FILE * outFile) {
    char chr[256];
    fgets(chr, 256, inFile);
    for(int i = 0; i < strlen(chr); i++) {
            if (chr[i] == '!') {
                putc('.', outFile);
            } else {
                if (chr[i] == ':') {
                    putc('.', outFile);
                    putc('.', outFile);
                    putc('.', outFile);
                } else {
                    putc(chr[i], outFile);
                }
            }
    }
    fclose(inFile);
    fclose(outFile);
    printf("\nDone!");
}

int main() {
    printf("This program copy text from input file to output files without colons and exclamation points.\n");
    FILE * inFile, * outFile;
    inFile = inputFileName();
    outFile = outputFileName();
    copyWithoutColonAndExclamation(inFile, outFile);
    return 0;
}