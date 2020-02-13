#include <stdio.h>

void selectionsort(int array[], int n);


int main()
{
  int array[100], n, c;

  printf("Enter number of elements\n");
  scanf("%d", &n);

  printf("Enter %d integers\n", n);

  for (c = 0; c < n; c++)
    scanf("%d", &array[c]);

  selectionsort(array, n);

  printf("Sorted list in ascending order:\n");

  for (c = 0; c < n; c++)
    printf("%d\n", array[c]);

  return 0;
}


void selectionsort(int array[], int n){
  int c, position, swap, d;

  for (c = n-1; c > 0 ; c--)
  {
    position = c;

    for (d = c - 1; d >= 0; d--)
    {
      if (array[position] < array[d])
        position = d;
    }
    if (position != c)
    {
      swap = array[c];
      array[c] = array[position];
      array[position] = swap;
    }
  }
}
