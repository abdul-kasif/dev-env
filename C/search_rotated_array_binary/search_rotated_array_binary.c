#include <stdio.h>
#include <stdlib.h>
int search(const int *nums, int numsSize, int target) {
  int low = 0;
  int high = numsSize - 1;
  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (nums[mid] == target)
      return mid;

    if (nums[mid] >= nums[low]) {

      if (target >= nums[low] && target < nums[mid])
        high = mid - 1;

      else
        low = mid + 1;
    }

    else {

      if (target > nums[mid] && target <= nums[high])
        low = mid + 1;

      else
        high = mid - 1;
    }
  }
  return -1;
}
int main(void) {
  int numsSize, target;
  if (scanf("%d", &numsSize) != 1 || scanf("%d", &target) != 1 ||
      numsSize <= 0) {
    fprintf(stderr, "Invalid Input\n");
    return 1;
  }

  int *nums = malloc(numsSize * sizeof(*nums));
  if (nums == NULL) {
    fprintf(stderr, "Allocation Failed\n");
    return 1;
  }

  for (int i = 0; i < numsSize; i++) {
    if (scanf("%d", &nums[i]) != 1) {
      fprintf(stderr, "Invalid Input\n");
      free(nums);
      return 1;
    }
  }

  int res = search(nums, numsSize, target);
  printf("result: %d\n", res);
  free(nums);
  return 0;
}
