#include <stdio.h>
#include <stdlib.h>

int smallestLetter(const char *arr, int n, char k) {
  int low = 0;
  int high = n;

  while (low < high) {
    int mid = low + (high - low) / 2;
    if (arr[mid] <= k) {
      low = mid + 1;
    } else {
      high = mid;
    }
  }

  return arr[low % n];
}

int main(void) {
  int n;
  char k;

  if (scanf("%d", &n) != 1 || n <= 0) {
    fprintf(stderr, "Invalid Input\n");
    return 1;
  }

  if (scanf(" %c", &k) != 1) {
    fprintf(stderr, "Invalid Input\n");
    return 1;
  }

  char *arr = malloc(n * sizeof(*arr));
  if (arr == NULL) {
    fprintf(stderr, "Allocation Failed\n");
    return 1;
  }

  if (scanf("%s", arr) != 1) {
    fprintf(stderr, "Invalid Input\n");
    free(arr);
    return 1;
  }

  char res = smallestLetter(arr, n, k);
  printf("result: %c", res);

  printf("\n");
  free(arr);
  return 0;
}
