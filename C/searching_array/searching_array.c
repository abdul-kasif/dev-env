#include <stdio.h>
#include <stdlib.h>

// find the first occurance of the element and return it
int linearSearch(const int *arr, int n, int x) {
  for (int i = 0; i < n; i++) {
    if (arr[i] == x) {
      return i;
    }
  }
  return -1;
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
  printf("result: %d\n", res);
  free(arr);
  return 0;
}
