// Copyright 2025 NNTU-CS
#include <cstdint>
#include <algorithm>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
  uint64_t res = num;
  while (num != 1) {
    if (num % 2) {
      num = 3 * num + 1;
      res = max(res, num);
    }
    while (num % 2 == 0) num /= 2;
  }
  return res;
}

unsigned int collatzLen(uint64_t num) {
  if (num <= 0) return 0;
  unsigned int res = 1;
  while (num != 1) {
    if (num % 2 == 0) {
      num /= 2;
    } else {
      num = 3 * num + 1;
    }
    res++;
  }
  return res;
}

unsigned int seqCollatz(unsigned int *maxlen,
                        uint64_t lbound,
                        uint64_t rbound) {
  if (rbound % 2 == 0) rbound--;
  if (lbound % 2 == 0) lbound++;
  uint64_t num = 1;
  while (rbound >= lbound) {
    unsigned int len = collatzLen(rbound);
    if (*maxlen < len) {
      *maxlen = len;
      num = collatzMaxValue(rbound);
    }
    rbound -= 2;
  }
  return num;
}
