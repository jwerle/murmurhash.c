/**
 * `example.c' - murmurhash
 *
 * copyright (c) 2014-2025 joseph werle <joseph.werle@gmail.com>
 */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "murmurhash.h"

int main (void) {
  uint32_t seed = 0;
  const char *key = "kinkajou"; // // 0xb6d99cf8
  uint32_t hash = murmurhash(key, (uint32_t) strlen(key), seed);
  printf("murmurhash(%s) = 0x%x\n", key, hash);
  return 0;
}
