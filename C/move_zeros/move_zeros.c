#include <stdio.h>
#include <stdlib.h>

void moveZeros(int *arr, int n) {
  int writeIndex = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] != 0) {
      arr[writeIndex++] = arr[i];
    }
  }

  for (int i = writeIndex; i < n; i++) {
    arr[i] = 0;
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
  moveZeros(arr, n);

  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  free(arr);
  return 0;
}
