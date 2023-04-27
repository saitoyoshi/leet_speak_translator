#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
  char str[] = "leet";
  char decode_table[] = "137";
  char encode_table[] = "let";
  char *p;
  for (int i = 0; i < sizeof(str) / sizeof(str[0]); i++) {
    p = strchr(encode_table, str[i]);
    printf("%c", decode_table[p - encode_table]);
  }
  putchar('\n');
  exit(0);
}
