// Test different algorithms under heavy load to measure real performance
// differences

#include <limits.h>
#include <stdio.h>
// Method 1: Naive bit checking (loop through all bits)
int popcount_naive(unsigned int x) {
  int count = 0;
  while (x) {
    count += x & 1;
    x >>= 1;
  }
  return count;
}

// Method 2: Brian Kernighan’s algorithm (clears lowest set bit)
int popcount_kernighan(unsigned int x) {
  int count = 0;
  while (x) {
    x &= x - 1;
    count++;
  }
  return count;
}

// Method 3: Built-in GCC intrinsic (fastest on modern CPUs)
int popcount_builtin(unsigned int x) { return __builtin_popcount(x); }

// Method 4: Lookup table (fast, but uses memory)
static const unsigned char lookup[256] = {
    0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4, 1, 2, 2, 3, 2, 3, 3, 4,
    2, 3, 3, 4, 3, 4, 4, 5, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 1, 2, 2, 3, 2, 3, 3, 4,
    2, 3, 3, 4, 3, 4, 4, 5, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6,
    4, 5, 5, 6, 5, 6, 6, 7, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 2, 3, 3, 4, 3, 4, 4, 5,
    3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6,
    4, 5, 5, 6, 5, 6, 6, 7, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
    4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8};

int popcount_lookup(unsigned int x) {
  return lookup[x & 0xFF] + lookup[(x >> 8) & 0xFF] + lookup[(x >> 16) & 0xFF] +
         lookup[(x >> 24) & 0xFF];
}

// SELECT YOUR METHOD HERE (change this number!)
#define METHOD 3 // 1=naive, 2=kernighan, 3=builtin, 4=lookup

long long total = 0; // volatile to prevent optimization

int main(void) {
  const unsigned int MAX_N = 10000000; // 10 million - adjust for your CPU

  for (unsigned int i = 0; i <= MAX_N; i++) {
#if METHOD == 1
    total += popcount_naive(i);
#elif METHOD == 2
    total += popcount_kernighan(i);
#elif METHOD == 3
    total += popcount_builtin(i);
#elif METHOD == 4
    total += popcount_lookup(i);
#else
#error "Invalid METHOD"
#endif
  }

  // Prevent compiler from optimizing away the loop
  printf("%lld\n", total);
  return 0;
}
