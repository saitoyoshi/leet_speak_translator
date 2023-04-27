#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    const char *character;
    const char *replacement;
} Translation;

const Translation leet_encode_table[] = {
    {"A", "4"}, {"B", "8"}, {"C", "<"}, {"D", "|)"}, {"E", "3"},
    {"F", "|="}, {"G", "6"}, {"H", "|-|"}, {"I", "1"}, {"J", "_|"},
    {"K", "|<"}, {"L", "1"}, {"M", "|\\/|"}, {"N", "|\\|"}, {"O", "0"},
    {"P", "|D"}, {"Q", "(,)"}, {"R", "|2"}, {"S", "5"}, {"T", "7"},
    {"U", "|_|"}, {"V", "\\/"}, {"W", "|/\\|"}, {"X", "><"}, {"Y", "`/"},
    {"Z", "2"}, {NULL, NULL}
};

const Translation leet_decode_table[] = {
    {"4", "A"}, {"8", "B"}, {"<", "C"}, {"|)", "D"}, {"3", "E"},
    {"|=", "F"}, {"6", "G"}, {"|-|", "H"}, {"1", "I"}, {"_|", "J"},
    {"|<", "K"}, {"1", "L"}, {"|\\/|", "M"}, {"|\\|", "N"}, {"0", "O"},
    {"|D", "P"}, {"(,)", "Q"}, {"|2", "R"}, {"5", "S"}, {"7", "T"},
    {"|_|", "U"}, {"\\/", "V"}, {"|/\\|", "W"}, {"><", "X"}, {"`/", "Y"},
    {"2", "Z"}, {NULL, NULL}
};
int find_matching_substring(const char *input, const Translation *table) {
    for (const Translation *t = table; t->character; ++t) {
        if (strncmp(input, t->replacement, strlen(t->replacement)) == 0) {
            return t - table;
        }
    }
    return -1;
}

void translate(const char *input, char *output, const Translation *table) {
    while (*input) {
        const Translation *matched_entry = NULL;
        for (const Translation *t = table; t->character; ++t) {
            if (toupper(*input) == *t->character) {
                matched_entry = t;
                break;
            }
        }

        if (matched_entry) {
            strcpy(output, matched_entry->replacement);
            output += strlen(matched_entry->replacement);
        } else {
            *output++ = *input;
        }
        ++input;
    }
    *output = '\0';
}

void translate_decode(const char *input, char *output, const Translation *table) {
    while (*input) {
        int matched_index = find_matching_substring(input, table);
        if (matched_index != -1) {
            strcpy(output, table[matched_index].character);
            output += strlen(table[matched_index].character);
            input += strlen(table[matched_index].replacement);
        } else {
            *output++ = *input++;
        }
    }
    *output = '\0';
}


int main(int argc, char **argv) {
    // const char *input = "H3ll0, W0r|_|)!";
    char *input = argv[1];
    char encoded[256];
    char decoded[256];

    translate(input, encoded, leet_encode_table);
    translate_decode(input, decoded, leet_decode_table);

    printf("Input: %s\n", input);
    printf("Encoded: %s\n", encoded);
    printf("Decoded: %s\n", decoded);

    return 0;
}
