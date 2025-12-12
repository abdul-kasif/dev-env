#include <stdio.h>
#include <stdlib.h>
int peakElement(const int *arr, int n) {
  int low = 0;
  int high = n - 1;
  while (low < high) {
    int mid = low + (high - low) / 2;
    if (arr[mid] > arr[mid + 1]) {
      high = mid;
    } else {
      low = mid + 1;
    }
  }
  return low;
}
int main(void) {
  int n;
  if (scanf("%d", &n) != 1 || n <= 0) {
    fprintf(stderr, "Invalid Input\n");
    return 1;
  }

  int *arr = malloc(n * sizeof(*arr));
  if (arr == NULL) {
    fprintf(stderr, "Allocation Failed");
    return 1;
  }

  for (int i = 0; i < n; i++) {
    if (scanf("%d", &arr[i]) != 1) {
      fprintf(stderr, "Invalid Input\n");
      free(arr);
      return 1;
    }
  }
  printf("%d\n", peakElement(arr, n));
  free(arr);
  return 0;
}
