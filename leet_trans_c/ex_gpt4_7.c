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

// [省略] 以前のコードと同じです。変更されていないtranslate, find_matching_substring関数など

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
