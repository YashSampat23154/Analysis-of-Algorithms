#include <stdio.h>
#include <stdlib.h>

struct array{
  int data;
  struct array* next;
  struct array* prev;
};

struct array* insertelement(struct array* node, int no);
struct array* insertionsort(struct array* node, int n);


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

  node = insertionsort(node, n);

  printf("Sorted list in ascending order:\n");

  ptr = node;

  while(ptr!=NULL) {
    printf("%d\n", ptr->data);
    ptr = ptr->next;
  }

  return 0;

}

struct array* insertionsort(struct array* node, int n){

  int c,d,t,p;

  for (c = 1 ; c <= n - 1; c++) {

    struct array* ptr = node;

    p = c;
    while(p>0)
    {
      ptr = ptr->next;
      p--;
    }

    d = c;

    while ( d > 0 && ptr->prev->data > ptr->data) {
      t = ptr->data;
      ptr->data = ptr->prev->data;
      ptr->prev->data = t;

      ptr = ptr->prev;

      d--;
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
