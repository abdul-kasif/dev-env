#include <stdio.h>
#include <stdlib.h>

void reverse(int *arr, int start, int end) {
  while (start < end) {
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
    start++;
    end--;
  }
}

void rotateArray(int *arr, int n, int k) {

  k = k % n;

  reverse(arr, n - k, n - 1);

  reverse(arr, 0, n - k - 1);

  reverse(arr, 0, n - 1);
}
int main(void) {
  int n, k;
  if (scanf("%d", &n) != 1 || scanf("%d", &k) != 1 || n <= 0 || k < 0) {
    fprintf(stderr, "Invalid inputs\n");
    return 1;
  }

  int *arr = malloc(n * sizeof(*arr));
  if (arr == NULL) {
    fprintf(stderr, "Allocation failed\n");
    return 1;
  }

  for (int i = 0; i < n; i++) {
    if (scanf("%d", &arr[i]) != 1) {
      fprintf(stderr, "Invalid inputs\n");
      free(arr);
      return 1;
    }
  }
  rotateArray(arr, n, k);
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  free(arr);
  return 0;
}
