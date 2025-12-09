#include <stdio.h>
#include <stdlib.h>

// find the all occurance of the element and return the indices
int linearSearch(const int *arr, int n, int x) {
  int count = 0;
  printf("indices: ");
  for (int i = 0; i < n; i++) {
    if (arr[i] == x) {
      count++;
      printf("%d ", i);
    }
  }
  printf("\n");
  return count;
}

int main(void) {
  int n, x;
  if (scanf("%d", &n) != 1 || scanf("%d", &x) != 1 || n <= 0) {
    fprintf(stderr, "Invalid Input\n");
    return 1;
  }

  int *arr = malloc(n * sizeof(*arr));
  if (arr == NULL) {
    fprintf(stderr, "Allocation failed\n");
    return 1;
  }

  for (int i = 0; i < n; i++) {
    if (scanf("%d", &arr[i]) != 1) {
      fprintf(stderr, "Invalid Input\n");
      free(arr);
      return 1;
    }
  }
  int res = linearSearch(arr, n, x);
  printf("count: %d\n", res);
  free(arr);
  return 0;
}
