#include <stdio.h>
#include <stdlib.h>

struct array{
  int data;
  struct array* next;
  struct array* prev;
};

struct array* insertelement(struct array* node, int no);
struct array* selectionsort(struct array* node, int n);


int main()
{
  int n, c, no;

  struct array* node = NULL;
  struct array* ptr = NULL;

  printf("Enter number of elements\n");
  scanf("%d", &n);

  printf("Enter %d integers\n", n);

  for (c = 0; c < n; c++)
  {
    scanf("%d",&no);
    node = insertelement(node, no);
  }

  node = selectionsort(node, n);

  printf("Sorted list in ascending order:\n");

  ptr = node;

  while(ptr!=NULL) {
    printf("%d\n", ptr->data);
    ptr = ptr->next;
  }

  return 0;

}

struct array* selectionsort(struct array* node, int n){

  int c,d,t,p,position;

  for (c = 0 ; c < n-1 ; c++) {

    struct array* ptr_position = node;
    struct array* ptr1;
    struct array* ptr2 = node;

    position = c;
    p = c;

    while(p>0)
    {
      ptr_position = ptr_position->next;
      ptr2 = ptr2->next;
      p--;
    }

    ptr1 = ptr_position;
    ptr2 = ptr2->next;

    d = c+1;

    while (d < n) {
      if(ptr1->data > ptr2->data)
      {
        while(d-position!=0){
          ptr1 = ptr1->next;
          position++;
        }
      }
      ptr2 = ptr2->next;
      d++;
    }

    if(position!=c)
    {
      t = ptr_position->data;
      ptr_position->data = ptr1->data;
      ptr1->data = t;
    }

  }

  return node;
}

struct array* insertelement(struct array* node, int no){

  struct array* ptr = node;
  struct array* preptr = node;

  if(node==NULL){
    node = (struct array*)malloc(sizeof(struct array*));
    node->data = no;
    node->next = NULL;
    node->prev = NULL;
  }
  else{
    ptr = node;
    preptr = node;
    while(ptr!=NULL){
      preptr = ptr;
      ptr = ptr->next;
    }
    ptr = (struct array*)malloc(sizeof(struct array*));
    ptr->data = no;
    ptr->next = NULL;
    ptr->prev = preptr;
    preptr->next = ptr;
  }

  return node;
}
