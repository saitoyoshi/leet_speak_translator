#include <stdio.h>
#include <ctype.h>

void leet_encode(const char *input, char *output) {
    for (; *input; ++input, ++output) {
        char c = toupper(*input);
        switch (c) {
            case 'A': *output = '4'; break;
            case 'B': *output = '8'; break;
            case 'E': *output = '3'; break;
            case 'G': *output = '6'; break;
            case 'I': *output = '1'; break;
            case 'L': *output = '7'; break;
            case 'O': *output = '0'; break;
            case 'S': *output = '5'; break;
            case 'T': *output = '7'; break;
            default: *output = *input;
        }
    }
    *output = '\0';
}
void leet_decode(const char *input, char *output) {
    for (; *input; ++input, ++output) {
        char c = toupper(*input);
        switch (c) {
            case '4': *output = 'A'; break;
            case '8': *output = 'B'; break;
            case '3': *output = 'E'; break;
            case '6': *output = 'G'; break;
            case '1': *output = 'I'; break;
            case '7': *output = 'L'; break;
            case '0': *output = 'O'; break;
            case '5': *output = 'S'; break;
            default: *output = *input;
        }
    }
    *output = '\0';
}
#include <stdio.h>

int main(int argc, char **argv) {
  if (argc != 2) {
    puts("again");
    exit(8);
  }
    char *input = argv[1];
    char encoded[256];
    char decoded[256];

    leet_encode(input, encoded);
    leet_decode(encoded, decoded);

    printf("Input: %s\n", input);
    printf("Encoded: %s\n", encoded);
    printf("Decoded: %s\n", decoded);

    return 0;
}
