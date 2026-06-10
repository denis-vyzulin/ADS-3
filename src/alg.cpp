// Copyright 2025 NNTU-CS
#include <cstdint>
#include <algorithm>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
  uint64_t mx_num = num;
  while (num != 1) {
    if (num % 2) num = 3 * num + 1;
    else num /= 2;
    mx_num = mx_num < num ? num : mx_num;
  }
  return mx_num;
}

unsigned int collatzLen(uint64_t num) {
  unsigned int len = 1;
  while (num != 1) {
    if (num % 2) num = 3 * num + 1;
    else num /= 2;
    len++;
  }
  return len;
}

unsigned int seqCollatz(unsigned int *maxlen,
                        uint64_t lbound,
                        uint64_t rbound) {
  *maxlen = 1;
  uint64_t num = 1;
  while (lbound <= rbound) {
    unsigned int len = collatzLen(lbound);
    if (len > *maxlen) {
      *maxlen = len;
      num = lbound;
    }
  }
  return num;
}
