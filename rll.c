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
  ptr = linkedlist;
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

int main() {

  insertatstart(14);
  insertatstart(17);
  insertatstart(4);
  printlist();
  printf("the current list adding all to start\n");
  insertatend(88);
  insertatend(89);
  insertatend(90);
  insertatend(91);
  printf("the current list adding all to end\n");
  printlist();
  deleteatbegin();
  deleteatbegin();
  deleteatend();
  printf("the current list after deleting first 2 and last one \n");
  printlist();

  return (0);
}
