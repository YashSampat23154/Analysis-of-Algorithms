#include <stdio.h>
#include <stdlib.h>

struct array{
  int data;
  struct array* next;
};

struct array* insertelement(struct array* node, int no);
struct array* mergesort(struct array* node, int beg, int end);
struct array* merge(struct array* node, int beg, int mid, int end);
void display(struct array* node);

struct array* new_node = NULL;

int main()
{
  int n, c, no;

  struct array* ptr = NULL;
  struct array* node = NULL;

  printf("Enter number of elements\n");
  scanf("%d", &n);

  printf("Enter %d integers\n", n);

  for (c = 0; c < n; c++)
  {
    scanf("%d",&no);
    node = insertelement(node, no);
    new_node = insertelement(new_node, -1);
  }

  node = mergesort(node, 0,n-1);

  printf("Sorted list in ascending order:\n");

  ptr = node;

  while(ptr!=NULL){
    printf("%d\n", ptr->data);
    ptr = ptr->next;
  }

  return 0;

}

struct array* mergesort(struct array* node, int beg, int end){
  int mid;
  if(beg<end)
  {
    mid=(beg+end)/2;
    node = mergesort(node,beg,mid);
    node = mergesort(node,mid+1,end);
    node = merge(node,beg,mid,end);
  }

  return (node);
}

struct array* merge(struct array* node, int beg, int mid, int end){

    int i = 0, j = 0,t;

    struct array* ptr1 = node;
    struct array* ptr2 = new_node;
    struct array* ptr3 = node;

    while(i<beg)
    {
      ptr1 = ptr1->next;
      ptr2 = ptr2->next;
      i++;
    }

    for(i=beg;i<=end;i++)
    {
      ptr2->data = ptr1->data;
      ptr2 = ptr2->next;
      ptr1 = ptr1->next;
    }

    ptr1 = new_node;
    ptr2 = new_node;

    i=0;

    while(i<beg)
    {
      ptr1 = ptr1->next;
      ptr3 = ptr3->next;
      i++;
    }
    while(j<=mid)
    {
      ptr2 = ptr2->next;
      j++;
    }


    while((i<=mid)&&(j<=end))
    {

      if(ptr1->data<ptr2->data)
      {
        ptr3->data = ptr1->data;
        ptr1 = ptr1->next;
        ptr3 = ptr3->next;
        i++;
      }
      else
      {
        ptr3->data = ptr2->data;
        ptr2=ptr2->next;
        ptr3 = ptr3->next;
        j++;
      }

    }

    if(i<=mid)
    {
      while(i<=mid)
      {
        ptr3->data = ptr1->data;
        ptr1=ptr1->next;
        ptr3 = ptr3->next;
        i++;
      }
    }
    else
    {
      while(j<=end)
      {
        ptr3->data = ptr2->data;
        ptr2=ptr2->next;
        ptr3 = ptr3->next;
        j++;
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
    preptr->next = ptr;
  }

  return node;
}

void display(struct array* node){
  printf("\n");
  struct array* ptr = node;
  while(ptr!=NULL){
    printf("%d  ",ptr->data);
     ptr = ptr->next;
  }
  printf("\n\n");

}
