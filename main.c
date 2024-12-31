/**
 * `main.c' - murmurhash
 *
 * copyright (c) 2014-2025 joseph werle <joseph.werle@gmail.com>
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <inttypes.h>

#include "murmurhash.h"

#define hash(key) murmurhash(key, (uint32_t) strlen(key), (uint32_t) atoi(seed));
#define isopt(opt, str) (0 == strncmp(opt, str, strlen(str)))
#define setopt(opt, key, var) {               \
  size_t len = strlen(key) + 1;               \
  for (int i = 0; i < len; ++i) { (*opt)++; } \
  var = opt;                                  \
}

static void usage () {
  fprintf(stderr, "usage: murmur [-hV] [options]\n");
}

static void help () {
  fprintf(stderr, "\noptions:\n");
  fprintf(stderr, "\n  --seed=[seed]  hash seed (optional)");
  fprintf(stderr, "\n");
}

static char* read_stdin () {
  size_t bsize = 1024;
  size_t size = 1;
  char buf[bsize];
  char *res = (char *) malloc(sizeof(char) * bsize);
  char *tmp = NULL;

  // memory issue
  if (NULL == res) { return NULL; }

  // cap
  res[0] = '\0';

  // read
  if (NULL != fgets(buf, bsize, stdin)) {
    // store
    tmp = res;
    // resize
    size += (size_t) strlen(buf);
    // realloc
    res = (char *) realloc(res, size);

    // memory issues
    if (NULL == res) {
      free(tmp);
      return NULL;
    }

    // yield
    strcat(res, buf);

    return res;
  }

  free(res);

  return NULL;
}

int main (int argc, char** argv) {
  char* buf = NULL;
  char* key = NULL;
  char* seed = NULL;
  uint32_t h = 0;

  // parse opts
  do {
    char* opt = NULL;
    opt = *argv++; // unused

    while ((opt = *argv++)) {

      // flags
      if ('-' == *opt++) {
        switch (*opt++) {
          case 'h':
            return usage(), help(), 0;

          case 'V':
            fprintf(stderr, "%s\n", MURMURHASH_VERSION);
            return 0;

          case '-':
            if (isopt(opt, "seed")) {
              setopt(opt, "seed", seed);
            }
            break;

          default:
            (*opt)--;
            // error
            fprintf(stderr, "unknown option: `%s'\n", opt);
            usage();
            return 1;
        }
      }
    }
  } while (0);

  if (NULL == seed) {
    seed = "0";
  }

  if (1 == isatty(0)) { return 1; }
  else if (ferror(stdin)) { return 1; }
  else {
    buf = read_stdin();
    if (NULL == buf) { return 1; }
    else if (0 == strlen(buf)) { buf = ""; }
    h = hash(buf);
    printf("%" PRIu32 "\n", h);
    do {
      key = read_stdin();
      if (NULL == key) { break; }
      else if (0 == strlen(buf)) { buf = ""; }
      h = hash(buf);
      printf("%d" PRIu32 "\n", h);
    } while (NULL != key);
  }

  return 0;
}
