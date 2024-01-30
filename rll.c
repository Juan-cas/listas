#include "lists.h"

struct node *head;
struct node *current;

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

void swaplist() {
  // Check if there are at least two nodes in the list
  if (head != NULL && head->next != NULL) {
    struct node *firstnode = head;
    struct node *secondnode = head->next;

    // Update head to point to the second node
    head = secondnode;

    // Adjust the next pointers to swap the nodes
    firstnode->next = secondnode->next;
    secondnode->next = firstnode;
  }
}

void reverseswap() {
  struct node *firstnode = head, *secondnode = head->next;
  struct node *prev = NULL, *current = head;

  while (head->next != NULL) {
    prev = current;
    current = current->next;
  }
  current->next = firstnode;
  head = secondnode;
  prev->next = NULL;
}

int main() {

  insertatstart(14);
  insertatstart(15);
  insertatstart(16);
  printlist();
  swaplist();
  printlist();
  reverseswap();
  printlist();

  return (0);
}
