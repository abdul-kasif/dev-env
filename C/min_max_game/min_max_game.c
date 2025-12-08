#include <stdio.h>
#include <stdlib.h>

int MinMaxGame(int *arr, int n) {
  if (n == 1)
    return arr[0];
  int *newArr = malloc((n / 2) * sizeof(*newArr));
  for (int i = 0; i < n / 2; i++) {
    if (i % 2 == 0) {
      newArr[i] = (arr[2 * i] < arr[2 * i + 1]) ? arr[2 * i] : arr[2 * i + 1];
    } else {
      newArr[i] = (arr[2 * i] > arr[2 * i + 1]) ? arr[2 * i] : arr[2 * i + 1];
    }
  }

  return MinMaxGame(newArr, n / 2);
  free(newArr);
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
  int res = MinMaxGame(arr, n);
  printf("%d\n", res);
  free(arr);
  return 0;
}
