#include <stdio.h>
#include <stdlib.h>

int binarySearch(const int *arr, int n, int target) {
  int low = 0;
  int high = n;

  while (low < high) {
    int mid = low + (high - low) / 2;
    if (arr[mid] < target) {
      low = mid + 1;
    } else {
      high = mid;
    }
  }
  return low;
}
int main(void) {
  int n, target;
  if (scanf("%d", &n) != 1 || scanf("%d", &target) != 1 || n <= 0) {
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
  int res = binarySearch(arr, n, target);
  printf("result: %d\n", res);
  free(arr);
  return 0;
}
