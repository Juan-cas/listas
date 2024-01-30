#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};


void printlist();
void insertatstart(int data);
void insertatend(int data);
void insertafternode(struct node *list, int data);
void deleteatbegin();
void deleteatend();
void deletenode(int key);
int searchlist(int key);
