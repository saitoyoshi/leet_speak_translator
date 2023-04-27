#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char character;
    const char *replacement;
} Translation;

const Translation leet_encode_table[] = {
    {'A', "4"}, {'B', "8"}, {'E', "3"}, {'G', "6"}, {'I', "1"},
    {'L', "7"}, {'O', "0"}, {'S', "5"}, {'T', "7"}, {'\0', NULL}
};

const Translation leet_decode_table[] = {
    {'4', "A"}, {'8', "B"}, {'3', "E"}, {'6', "G"}, {'1', "I"},
    {'7', "L"}, {'0', "O"}, {'5', "S"}, {'\0', NULL}
};

void translate(const char *input, char *output, const Translation *table) {
    for (; *input; ++input) {
        int replaced = 0;
        for (const Translation *t = table; t->character; ++t) {
            if (toupper(*input) == t->character) {
                strcpy(output, t->replacement);
                output += strlen(t->replacement);
                replaced = 1;
                break;
            }
        }
        if (!replaced) {
            *output++ = *input;
        }
    }
    *output = '\0';
}

int main() {
    const char *input = "Hello, World!";
    char encoded[256];
    char decoded[256];

    translate(input, encoded, leet_encode_table);
    translate(encoded, decoded, leet_decode_table);

    printf("Input: %s\n", input);
    printf("Encoded: %s\n", encoded);
    printf("Decoded: %s\n", decoded);

    return 0;
}
