#include "./codeGenerator.h"
#include "./instructions.h"
#include "./template.h"

#include <stdlib.h>
#include <string.h>

/**
 * Generate simple code from a given brainfuck string and return a pointer to it.
 */
char* generateCodeFromBf(const char* bf) {
    char* code = malloc(sizeof(""));
    code = realloc(code, strlen(code) + strlen(DEFAULT_CODE_HEADERS) + 1);
    strcat(code, DEFAULT_CODE_HEADERS);

    for (__uint128_t i = 0; i < strlen(bf); i++) {
        const char instruction = bf[i];
        char* cCode = NULL;
        switch (instruction) {
            case INCREMENT:
                cCode = "(*p)++;";
                break;

            case DECREMENT:
                cCode = "(*p)--;";
                break;

            case MOVE_RIGHT:
                cCode = "p++;";
                break;

            case MOVE_LEFT:
                cCode = "p--;";
                break;
        }
        if (cCode != NULL) {
            code = realloc(code, strlen(code) + strlen(cCode) + 1);
            strcat(code, cCode);
        }
    }

    code = realloc(code, strlen(code) + strlen(DEFAULT_CODE_FOOTER) + 1);
    strcat(code, DEFAULT_CODE_FOOTER);

    return code;
}