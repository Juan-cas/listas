#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;

void printlist() {
  struct node *p = head;

  printf("\n[");

  while (p != NULL) {
    printf(" %d ", p->data);
    p = p->next;
  }
  printf("]");
}

void insertatstart(int data) {
  struct node *nlk = (struct node *)malloc(sizeof(struct node));
  nlk->data = data;
  nlk->next = head;
  head = nlk;
}

void insertatend(int data) {
  struct node *nlk = (struct node *)malloc(sizeof(struct node));
  nlk->data = data;
  struct node *linkedlist = head;
  while (linkedlist->next != NULL)
    linkedlist = linkedlist->next;

  linkedlist->next = nlk;
}

void insertafternode(struct node *list, int data) {
  struct node *nlk = (struct node *)malloc(sizeof(struct node));
  nlk->data = data;
  nlk->next = list->next;
  list->next = nlk;
}

void deleteatbegin() {
  struct node *ptr;

  ptr = head;
  head = head->next;
  free(ptr);
}

void deleteatend() {
  struct node *linkedlist = head;
  struct node *ptr;
  while (linkedlist->next->next != NULL)
    linkedlist = linkedlist->next;
  ptr = linkedlist->next;
  linkedlist->next = NULL;
  free(ptr);
}

void deletenode(int key) {
  struct node *temp = head, *prev;
  struct node *ptr;
  if (temp != NULL && temp->data == key) {
    head = temp->next;
    return;
  }

  while (temp != NULL && temp->data != key) {
    prev = temp;
    temp = temp->next;
  }
  if (temp == NULL)
    return;
  ptr = prev;
  prev->next = temp->next;
  free(ptr);
}

int searchlist(int key) {
  struct node *temp = head;
  while (temp != NULL) {
    if (temp->data == key)
      return (1);
    temp = temp->next;
  }
  return 0;
}

void swap()
{
  struct node *firstnode, *secondnode, *prev;
  firstnode = head;
  secondnode = head->next;
  prev = secondnode->next;
  head = secondnode;
  head->next = firstnode;
  head->next->next = prev;
}

void reverseswap()
{
  struct node *firstnode, *secondnode, *prev = NULL, *current = head;
  firstnode = head;
  secondnode = head->next;
  while (current->next != NULL)
  {
    prev = current;
    current = current->next;
  }
  head = current;
  head->next = secondnode;
  prev->next = firstnode;
  firstnode->next = NULL;
}

int main() {

  insertatstart(5);
  insertatstart(3);
  insertatstart(4);
  printlist();
  printf("\n this is the list before swap");
  swap();
  printlist();
  printf("\n this is the list after the swap");
  reverseswap();
  printlist();
  printf("\n this is the list after the reverseswap");
  return (0);
}
