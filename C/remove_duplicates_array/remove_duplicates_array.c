#include <stdio.h>
#include <stdlib.h>

int removeDuplicates(int *arr, int n) {
  int ptr = 0;
  for (int i = 0; i < n; i++) {
    if (arr[ptr] != arr[i]) {
      arr[++ptr] = arr[i];
    }
  }
  return ++ptr;
}
int main(void) {
  int n;
  if (scanf("%d", &n) != 1 || n <= 0) {
    fprintf(stderr, "Invalid Input");
    return 1;
  }

  int *arr = malloc(n * sizeof(*arr));
  if (arr == NULL) {
    fprintf(stderr, "allocation failed");
    return 1;
  }

  for (int i = 0; i < n; i++) {
    if (scanf("%d", &arr[i]) != 1) {
      fprintf(stderr, "invaild input");
      free(arr);
      return 1;
    }
  }

  int k = removeDuplicates(arr, n);
  printf("%d\n", k);
  for (int i = 0; i < k; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  free(arr);
  return 0;
}
