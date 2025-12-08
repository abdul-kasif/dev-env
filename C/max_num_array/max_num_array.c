#include <stdio.h>
#include <stdlib.h>

int findMax(int arr[], int n) {
  int MAX = arr[0];
  for (int i = 0; i < n; i++) {
    if (arr[i] > MAX) {
      MAX = arr[i];
    }
  }
  return MAX;
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
  printf("%d\n", findMax(arr, n));
  free(arr);
  return 0;
}
