#include <stdio.h>
#include <stdlib.h>

void reverseArray(int *arr, int n) {
  for (int i = 0; i < n / 2; i++) {
    int temp = arr[i];
    arr[i] = arr[n - 1 - i];
    arr[n - 1 - i] = temp;
  }
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
  reverseArray(arr, n);
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }

  printf("\n");
  free(arr);
  return 0;
}
