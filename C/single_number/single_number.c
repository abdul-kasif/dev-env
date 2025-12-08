#include <stdio.h>
#include <stdlib.h>

int singleNumber(int *arr, int n) {
  int result = 0;
  for (int i = 0; i < n; i++) {
    result ^= arr[i];
  }

  return result;
}
int main() {
  int n;
  if (scanf("%d", &n) != 1 || n <= 0) {
    fprintf(stderr, "Invalid input\n");
    return 1;
  }

  // Allocation to the heap
  int *arr = malloc(n * sizeof(*arr));
  if (arr == NULL) {
    fprintf(stderr, "Allocation Failed\n");
    return 1;
  }

  for (int i = 0; i < n; i++) {
    if (scanf("%d", &arr[i]) != 1) {
      fprintf(stderr, "Invalid array element\n");
      free(arr);
      return 1;
    }
  }

  int res = singleNumber(arr, n);
  printf("%d\n", res);
  free(arr);
  return 0;
}
