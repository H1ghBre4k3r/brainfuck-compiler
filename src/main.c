#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./codeGenerator.h"

#define COMPILER_STATEMENT "echo \'%s\' | gcc -o generated/bf -xc -w -"

char* bf =
    "++++++++++[ > +++++++ > ++++++++++ > +++ > + < < < < -] Schleife zur Vorbereitung der Textausgabe >++.Ausgabe von "
    "'H' > +.Ausgabe von 'e' +++++++.'l'.'l' +++.'o' >++.Leerzeichen << +++++++++++++++.'W' >.'o' +++.'r' ------.'l' "
    "--------.'d' >+.'!' >.Zeilenvorschub ";

/**
 * Write a string to a file.
 */
void writeToFile(const char* value, const char* filename) {
    FILE* file = fopen(filename, "w+");
    fprintf(file, "%s", value);
    fclose(file);
}

int main() {
    char* code = generateCodeFromBf(bf);
    writeToFile(code, "./generated/bf.c");
    char* output = malloc(strlen(code) + strlen(COMPILER_STATEMENT) + 1);
    sprintf(output, COMPILER_STATEMENT, code);
    system(output);
}