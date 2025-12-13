#include <stdio.h>
#include <stdlib.h>

int findMin(const int *nums, int numsSize) {
  int low = 0;
  int high = numsSize - 1;
  int MIN = nums[0];
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (nums[mid] < MIN) {
      MIN = nums[mid];
      high = mid - 1;
    } else {
      low = mid + 1;
    }

    printf("low: %d, high: %d, mid: %d, min: %d\n", low, high, mid, MIN);
  }

  return MIN;
}
int main(void) {
  int n;
  if (scanf("%d", &n) != 1 || n <= 0) {
    fprintf(stderr, "Invalid Input\n");
    return 1;
  }
  int *arr = malloc(n * sizeof(*arr));
  if (arr == NULL) {
    fprintf(stderr, "Allocation Failed\n");
    return 1;
  }

  for (int i = 0; i < n; i++) {
    if (scanf("%d", &arr[i]) != 1) {
      fprintf(stderr, "Invalid Input\n");
      free(arr);
      return 1;
    }
  }
  printf("output: %d\n", findMin(arr, n));
  free(arr);
  return 0;
}
