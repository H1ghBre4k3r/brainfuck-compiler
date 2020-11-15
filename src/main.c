#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "./codeGenerator.h"

#define COMPILER_STATEMENT "echo \'%s\' | gcc -o %s -xc -w -"

/**
 * Write a string to a file.
 */
void writeToFile(const char* value, const char* filename) {
    FILE* file = fopen(filename, "w+");
    fprintf(file, "%s", value);
    fclose(file);
}

/**
 * Read content from a file.
 */
char* readFromFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Cannot open file '%s'\n", filename);
        exit(1);
    }

    char* content = malloc(sizeof(""));
    char c;

    while ((c = fgetc(file)) != EOF) {
        content = realloc(content, strlen(content) + 1);
        content[strlen(content)] = c;
    }
    fclose(file);
    return content;
}

int main(const int argc, const char** argv) {
    if (argc < 3) {
        printf("Not enough arguments!\nUsage: %s <input> <output>\n", argv[0]);
        return 1;
    }

    const char* inputFile = argv[1];
    const char* outputFile = argv[2];

    const char* bf = readFromFile(inputFile);

    char* code = generateCodeFromBf(bf);
    char* output = malloc(strlen(code) + strlen(outputFile) + strlen(COMPILER_STATEMENT) + 1);
    sprintf(output, COMPILER_STATEMENT, code, outputFile);
    system(output);
}