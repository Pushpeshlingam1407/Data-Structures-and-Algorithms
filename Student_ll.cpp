#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
struct Node {
  int studentCode;
  char name[50];
  char course[50];
  float fees;
  char city[50];

  struct Node *next;
};
struct Node *head = NULL;

void create() {
  struct Node *newNode, *temp;
  int n, i;

  printf("How many Students : ");
  scanf("%d", &n);

  for (i = 1; i <= n; i++) {
    newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("\nEnter Student Code : ");
    scanf("%d", &newNode->studentCode);

    printf("Enter Student Name : ");
    scanf("%s", newNode->name);

    printf("Enter Course : ");
    scanf("%s", newNode->course);

    printf("Enter Fees : ");
    scanf("%f", &newNode->fees);

    printf("Enter City : ");
    scanf("%s", newNode->city);

    newNode->next = NULL;

    if (head == NULL) {
      head = newNode;
      temp = newNode;
    } else {
      temp->next = newNode;
      temp = newNode;
    }
  }
}
void display() {
  struct Node *temp;

  if (head == NULL) {
    printf("\nList Empty");
    return;
  }

  temp = head;

  printf("\n-------------------------------------------------------------");
  printf("\nCode\tName\tCourse\tFees\tCity");
  printf("\n-------------------------------------------------------------");

  while (temp != NULL) {
    printf("\n%d\t%s\t%s\t%.2f\t%s", temp->studentCode, temp->name,
           temp->course, temp->fees, temp->city);

    temp = temp->next;
  }

  printf("\n-------------------------------------------------------------");
}
void insertBegining() {
  struct Node *newNode;

  newNode = (struct Node *)malloc(sizeof(struct Node));

  printf("\nEnter Student Code : ");
  scanf("%d", &newNode->studentCode);

  printf("Enter Student Name : ");
  scanf("%s", newNode->name);

  printf("Enter Course : ");
  scanf("%s", newNode->course);

  printf("Enter Fees : ");
  scanf("%f", &newNode->fees);

  printf("Enter City : ");
  scanf("%s", newNode->city);

  newNode->next = head;
  head = newNode;
}

void insertEnd() {
  struct Node *newNode, *temp;

  newNode = (struct Node *)malloc(sizeof(struct Node));

  printf("\nEnter Student Code : ");
  scanf("%d", &newNode->studentCode);

  printf("Enter Student Name : ");
  scanf("%s", newNode->name);

  printf("Enter Course : ");
  scanf("%s", newNode->course);

  printf("Enter Fees : ");
  scanf("%f", &newNode->fees);

  printf("Enter City : ");
  scanf("%s", newNode->city);

  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
    return;
  }

  temp = head;

  while (temp->next != NULL) {
    temp = temp->next;
  }

  temp->next = newNode;
}
void insertPosition(int pos) {
  struct Node *newNode, *temp;
  int i;

  newNode = (struct Node *)malloc(sizeof(struct Node));

  printf("\nEnter Student Code : ");
  scanf("%d", &newNode->studentCode);

  printf("Enter Student Name : ");
  scanf("%s", newNode->name);

  printf("Enter Course : ");
  scanf("%s", newNode->course);

  printf("Enter Fees : ");
  scanf("%f", &newNode->fees);

  printf("Enter City : ");
  scanf("%s", newNode->city);

  if (pos == 1) {
    newNode->next = head;
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
  temp->next = newNode;
}
void deletePosition(int pos) {
  struct Node *temp, *deleteNode;
  int i;

  if (head == NULL) {
    printf("\nList is Empty");
    return;
  }

  if (pos == 1) {
    temp = head;

    printf("\nDeleted Student : %s", temp->name);

    head = head->next;

    free(temp);
    return;
  }

  temp = head;

  for (i = 1; i < pos - 1 && temp != NULL; i++) {
    temp = temp->next;
  }

  if (temp == NULL || temp->next == NULL) {
    printf("\nInvalid Position");
    return;
  }

  deleteNode = temp->next;

  printf("\nDeleted Student : %s", deleteNode->name);

  temp->next = deleteNode->next;

  free(deleteNode);
}
void deleteBegin() {
  struct Node *temp;

  if (head == NULL) {
    printf("\nList is Empty");
    return;
  }

  temp = head;

  printf("\nDeleted Student : %s", temp->name);

  head = head->next;

  free(temp);
}
void deleteEnd() {
  struct Node *temp;

  if (head == NULL) {
    printf("\nList is Empty");
    return;
  }

  if (head->next == NULL) {
    printf("\nDeleted Student : %s", head->name);

    free(head);
    head = NULL;
    return;
  }

  temp = head;

  while (temp->next->next != NULL) {
    temp = temp->next;
  }

  printf("\nDeleted Student : %s", temp->next->name);

  free(temp->next);

  temp->next = NULL;
}

void searchStudent(int code) {
  struct Node *temp;
  int pos = 1;

  temp = head;

  while (temp != NULL) {
    if (temp->studentCode == code) {
      printf("\nStudent Found at Position %d", pos);

      printf("\nCode   : %d", temp->studentCode);
      printf("\nName   : %s", temp->name);
      printf("\nCourse : %s", temp->course);
      printf("\nFees   : %.2f", temp->fees);
      printf("\nCity   : %s", temp->city);

      return;
    }

    temp = temp->next;
    pos++;
  }

  printf("\nStudent Not Found");
}
void reverseData() {
  struct Node *prev = NULL;
  struct Node *current = head;
  struct Node *next = NULL;

  while (current != NULL) {
    next = current->next;

    current->next = prev;

    prev = current;

    current = next;
  }

  head = prev;

  printf("\nStudent List Reversed Successfully");
}
int main() {
  int pos, value;

  create();

  display();
  printf("\nElements Creation Completed");
  insertBegining();
  display();
  printf("\nInsert begining Complete");
  insertEnd();
  display();
  printf("\nInsert End Completed");
  printf("\nEnter Which postion element you want insert with specified value");
  scanf("%d%d", &pos, &value);
  insertPosition(pos);
  display();
  printf("\nInsert Position Completed");
  printf("\nEnter Which postion element you want delete");
  scanf("%d", &pos);
  deletePosition(pos);
  display();
  printf("\nDelete Position is Completed");
  deleteBegin();
  display();
  printf("\nDelete Begin Completed");
  deleteEnd();
  display();
  printf("\nDelete End Completed");
  printf("\nEnter Search Element");
  scanf("%d", &value);
  searchStudent(1);

  printf("\nAfter Reverse");

  display();
  printf("NULL");

  return 0;
}