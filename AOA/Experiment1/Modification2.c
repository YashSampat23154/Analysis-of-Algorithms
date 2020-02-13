#include <stdio.h>
#include<stdlib.h>

void insertionsort(int *array[], int *n);

int main()
{
  int *n, *array[1000], *c;

  n = (int *)malloc(sizeof(int));
  c = (int *)malloc(sizeof(int));

  printf("Enter number of elements\n");
  scanf("%d", n);

  for(*c = 0; *c < *n; *c = *c + 1)
    array[*c] = (int *)malloc(sizeof(int));

  printf("Enter %d integers\n", *n);

  for (*c = 0; *c < *n; *c = *c + 1)
    scanf("%d", array[*c]);

  insertionsort(array, n);

  printf("Sorted list in ascending order:\n");

  for (*c = 0; *c < *n; *c = *c + 1)
    printf("%d\t", *array[*c]);

  printf("\n");

  return 0;
}


void insertionsort(int *array[], int *n){

  int *c,*d,*t;

  c = (int *)malloc(sizeof(int));
  d = (int *)malloc(sizeof(int));
  t = (int *)malloc(sizeof(int));

  for (*c = 1; *c <= *n - 1; *c = *c + 1) {
    *d = *c;

    while ( *d > 0 && *array[*d-1] > *array[*d]) {
      t = array[*d];
      array[*d]   = array[*d-1];
      array[*d-1] = t;

      *d = *d - 1;
    }
  }
}
