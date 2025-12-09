#include <stdio.h>
#include <stdlib.h>

// find the index of the closest element to the target
int linearSearch(const int *arr, int n, int k) {
  if (n == 1) {
    return 0;
  }
  int diff = abs(arr[0] - k);
  int index = 0;
  for (int i = 0; i < n; i++) {
    int m = abs(arr[i] - k);
    if (m < diff) {
      diff = m;
      index = i;
    }
  }
  return index;
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
