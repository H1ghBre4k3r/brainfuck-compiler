#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

/**
 * Enum of possible instructions.
 */
enum Instructions {
    INCREMENT = '+',
    DECREMENT = '-',
    MOVE_RIGHT = '>',
    MOVE_LEFT = '<',
    START_LOOP = '[',
    END_LOOP = ']',
    PRINT_CHAR = '.',
    GET_CHAR = ','
};
#endif