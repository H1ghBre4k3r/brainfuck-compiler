#include <stdio.h>

#include "./codeGenerator.h"

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
    const char* code = generateCodeFromBf(bf);
    writeToFile(code, "./generated/bf.c");
}