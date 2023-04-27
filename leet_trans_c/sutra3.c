#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
  char character;
  const char *replacement;
} Translation;

const Translation leet_encode_table[] = {
    {'A', "4"}, {'B', "8"}, {'C', "<"}, {'D', "|)"}, {'E', "3"},
    {'F', "|="}, {'G', "6"}, {'H', "|-|"}, {'I', "1"}, {'J', "_|"},
    {'K', "|<"}, {'L', "1"}, {'M', "|\\/|"}, {'N', "|\\|"}, {'O', "0"},
    {'P', "|D"}, {'Q', "(,)"}, {'R', "|2"}, {'S', "5"}, {'T', "7"},
    {'U', "|_|"}, {'V', "\\/"}, {'W', "|/\\|"}, {'X', "><"}, {'Y', "`/"},
    {'Z', "2"}, {'\0', NULL}
};

const Translation leet_decode_table[] = {
    {'4', "A"}, {'8', "B"}, {'<', "C"}, {'|)', "D"}, {'3', "E"},
    {'|=', "F"}, {'6', "G"}, {'|-|', "H"}, {'1', "I"}, {'_|', "J"},
    {'|<', "K"}, {'1', "L"}, {'|\\/|', "M"}, {'|\\|', "N"}, {'0', "O"},
    {'|D', "P"}, {'(,)', "Q"}, {'|2', "R"}, {'5', "S"}, {'7', "T"},
    {'|_|', "U"}, {'\\/', "V"}, {'|/\\|', "W"}, {'><', "X"}, {'`/', "Y"},
    {'2', "Z"}, {'\0', NULL}
};


void translate(const char *input, char *output, const Translation *table) {
  for (; *input; input++) {
    int replaced = 0;
    for (const Translation *t = table; t->character; t++) {
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
int main(int argc, char **argv)
{
  if (argc != 2) {
    exit(15);
  }
  const char *input = argv[1];
  char encoded[256];
  char decoded[256];

  translate(input, encoded, leet_encode_table);
  translate(input, decoded, leet_decode_table);

  printf("Input: %s\n", input);
  printf("Encoded: %s\n", encoded);
  printf("Decoded: %s\n", decoded);
  exit(0);
}
