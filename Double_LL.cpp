#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
struct Node {
  int data;
  struct Node *prev;
  struct Node *next;
};
struct Node *head = NULL;
void create() {
  struct Node *newNode, *temp;
  int n, i;

  printf("How many nodes: ");
  scanf("%d", &n);

  for (i = 1; i <= n; i++) {
    newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter Data: ");
    scanf("%d", &newNode->data);

    newNode->prev = NULL;
    newNode->next = NULL;

    if (head == NULL) {
      head = newNode;
      temp = newNode;
    } else {
      temp->next = newNode;
      newNode->prev = temp;
      temp = newNode;
    }
  }
}
void display() {
  struct Node *temp = head;

  printf("\nNULL <- ");

  while (temp != NULL) {
    printf("%d <-> ", temp->data);
    temp = temp->next;
  }

  printf("NULL\n");
}
void displayReverse() {
  struct Node *temp = head;

  if (head == NULL) {
    printf("List Empty");
    return;
  }

  while (temp->next != NULL) {
    temp = temp->next;
  }

  printf("\nReverse Display:\n");

  while (temp != NULL) {
    printf("%d <-> ", temp->data);
    temp = temp->prev;
  }

  printf("NULL");
}
void insertBegining(int data) {
  struct Node *newNode;

  newNode = (struct Node *)malloc(sizeof(struct Node));

  // printf("\nEnter value for inserting begin : ");
  // scanf("%d",&newNode->data);
  newNode->data = data;
  newNode->prev = NULL;
  newNode->next = head;

  if (head != NULL) {
    head->prev = newNode;
  }

  head = newNode;
}
void insertEnd() {
  struct Node *newNode, *temp;

  newNode = (struct Node *)malloc(sizeof(struct Node));

  printf("\nEnter value for inserting end : ");
  scanf("%d", &newNode->data);

  newNode->next = NULL;

  if (head == NULL) {
    newNode->prev = NULL;
    head = newNode;
    return;
  }

  temp = head;

  while (temp->next != NULL) {
    temp = temp->next;
  }

  temp->next = newNode;
  newNode->prev = temp;
}
void insertPosition(int pos, int value) {
  struct Node *newNode, *temp;
  int i;

  newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = value;

  if (pos == 1) {
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
      head->prev = newNode;

    head = newNode;
    return;
  }

  temp = head;

  for (i = 1; i < pos - 1 && temp != NULL; i++) {
    temp = temp->next;
  }

  if (temp == NULL) {
    printf("Invalid Position");
    free(newNode);
    return;
  }

  newNode->next = temp->next;
  newNode->prev = temp;

  if (temp->next != NULL)
    temp->next->prev = newNode;

  temp->next = newNode;
}
void deleteBeigin() {
  struct Node *temp;

  if (head == NULL) {
    printf("List Empty");
    return;
  }

  temp = head;
  head = head->next;

  if (head != NULL)
    head->prev = NULL;

  free(temp);
}
void deleteEnd() {
  struct Node *temp;

  if (head == NULL) {
    printf("List Empty");
    return;
  }

  if (head->next == NULL) {
    free(head);
    head = NULL;
    return;
  }

  temp = head;

  while (temp->next != NULL) {
    temp = temp->next;
  }

  temp->prev->next = NULL;

  free(temp);
}
void deletePosition(int pos) {
  struct Node *temp;
  int i;

  if (head == NULL) {
    printf("List Empty");
    return;
  }

  temp = head;

  if (pos == 1) {
    head = head->next;

    if (head != NULL)
      head->prev = NULL;

    free(temp);
    return;
  }

  for (i = 1; i < pos && temp != NULL; i++) {
    temp = temp->next;
  }

  if (temp == NULL) {
    printf("Invalid Position");
    return;
  }

  if (temp->next != NULL)
    temp->next->prev = temp->prev;

  temp->prev->next = temp->next;

  free(temp);
}
void searchData(int key) {
  struct Node *temp = head;
  int pos = 1;

  while (temp != NULL) {
    if (temp->data == key) {
      printf("Element Found at Position %d", pos);
      return;
    }

    temp = temp->next;
    pos++;
  }

  printf("Element Not Found");
}
void reverseData() {
  struct Node *current = head;
  struct Node *temp = NULL;

  while (current != NULL) {
    temp = current->prev;
    current->prev = current->next;
    current->next = temp;
    current = current->prev;
  }

  if (temp != NULL)
    head = temp->prev;
}
int main() {
  int data;
  create();
  display();
  displayReverse();
  printf("\nEnter value for inserting begin: ");
  scanf("%d", &data);
  insertBegining(data);
  display();
}