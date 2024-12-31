/**
 * `murmurhash.h' - murmurhash
 *
 * copyright (c) 2014-2025 joseph werle <joseph.werle@gmail.com>
 */
#ifndef MURMURHASH_H
#define MURMURHASH_H

#include <stdint.h>

#define MURMURHASH_VERSION "0.2.0"

#ifdef __cplusplus
extern "C" {
#endif
  /**
   * Returns a murmur hash of `key' based on `seed'
   * using the MurmurHash3 algorithm
   */

  uint32_t murmurhash (const char*, uint32_t, uint32_t);
#ifdef __cplusplus
}
#endif
#endif
