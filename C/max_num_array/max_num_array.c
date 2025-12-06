#include <stdio.h>
#include <stdlib.h>

int main() {
  int n;
  int max = 0;
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

  for (int i = 0; i < n; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }

  printf("%d\n", max);
  free(arr);
  return 0;
}
