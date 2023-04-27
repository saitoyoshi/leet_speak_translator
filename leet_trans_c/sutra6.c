#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <getopt.h>

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

// [省略] 以前のコードと同じです。変更されていないtranslate, find_matching_substring関数など
int find_matching_substring(const char *input, Translation *table, int use_character_field) {
  for (const Translation *t = table; t->character; t++) {
    const char *field_to_compare = use_character_field ? t->character : t->replacement;
    if (strncmp(input, field_to_compare, strlen(field_to_compare)) == 0) {
      return t - table;
    }
  }
  return -1;
}

void translate(const char *input, char *output, const Translation *table) {
  while (*input) {
    const Translation *matched_entry = NULL;
    for (const Translation *t = table; t->character; t++) {
      if (toupper(*input) == *(t->character)) {
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
    input++;
  }
  *output = '\0';
}

void translate_decode(const char *input, char *output, const Translation *table) {
  while(*input) {
    int matched_index = find_matching_substring(input, table, 1);
    if (matched_index != -1) {
      strcpy(output, table[matched_index].replacement);
      output += strlen(table[matched_index].replacement);
      input += strlen(table[matched_index].character);
    } else {
           *output++ = *input++;
    }
  }
  *output = '\0';
}

void print_usage(char *program_name) {
  printf("Usage: %s -d|-e|-h <input string>\n", program_name);
  printf("  -d : Decode the input string\n");
  printf("  -e : Encode the input string\n");
  printf("  -h : Display this help message\n");
}

int main(int argc, char **argv)
{
  int opt;
  int encode_flag = 0, decode_flag = 0;
  char *input = NULL;
  char encoded[256];
  char decoded[256];

  static struct option long_options[] = {
    {"encode", no_argument, 0, 'e'},
    {"decode", no_argument, 0, 'd'},
    {"help", no_argument, 0, 'h'},
    {0, 0, 0, 0}
  };

  int option_index = 0;
  while ((opt = getopt_long(argc, argv, "edh", long_options, &option_index)) != -1) {
    switch (opt) {
      case 'e':
        encode_flag = 1;
        break;
      case 'd':
        decode_flag = 1;
        break;
      case 'h':
      default:
        fprintf(stderr, "Usage: %s -e|-d|-h <input string>\n", argv[0]);
        exit(1);
    }
  }

  if (optind < argc) {
    input = argv[optind];
  } else {
    fprintf(stderr, "Usage: %s -e|-d|-h <input string>\n", argv[0]);
    exit(1);
  }

  if (encode_flag) {
    translate(input, encoded, leet_encode_table);
    printf("input: %s\n", input);
    printf("encoded: %s\n", encoded);
  } else if (decode_flag) {
    translate_decode(input, decoded, leet_decode_table);
    printf("input: %s\n", input);
    printf("decoded: %s\n", decoded);
  }

  return 0;
}
