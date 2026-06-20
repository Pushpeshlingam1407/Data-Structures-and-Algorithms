#include <iostream>
#include <string>
using namespace std;

struct Node {
  int studentCode;
  char name[50];
  char course[50];
  float fees;
  char city[50];
  Node *next;
};

Node *head = nullptr;

void readStudent(Node *node) {
  cout << "\nEnter Student Code : ";
  cin >> node->studentCode;
  cout << "Enter Student Name : ";
  cin >> node->name;
  cout << "Enter Course       : ";
  cin >> node->course;
  cout << "Enter Fees         : ";
  cin >> node->fees;
  cout << "Enter City         : ";
  cin >> node->city;
  node->next = nullptr;
}

void create() {
  int n;
  cout << "How many Students : ";
  cin >> n;

  Node *temp = nullptr;

  for (int i = 1; i <= n; i++) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    readStudent(newNode);

    if (head == nullptr) {
      head = newNode;
      temp = newNode;
    } else {
      temp->next = newNode;
      temp = newNode;
    }
  }
}

void display() {
  if (head == nullptr) {
    cout << "\nList Empty\n";
    return;
  }

  cout << "\n-------------------------------------------------------------\n";
  cout << "Code\tName\tCourse\tFees\tCity\n";
  cout << "-------------------------------------------------------------\n";

  Node *temp = head;
  while (temp != nullptr) {
    cout << temp->studentCode << "\t" << temp->name << "\t" << temp->course
         << "\t" << temp->fees << "\t" << temp->city << "\n";
    temp = temp->next;
  }

  cout << "-------------------------------------------------------------\n";
}

void insertBegining() {
  Node *newNode = (Node *)malloc(sizeof(Node));
  readStudent(newNode);
  newNode->next = head;
  head = newNode;
}

void insertEnd() {
  Node *newNode = (Node *)malloc(sizeof(Node));
  readStudent(newNode);

  if (head == nullptr) {
    head = newNode;
    return;
  }

  Node *temp = head;
  while (temp->next != nullptr)
    temp = temp->next;

  temp->next = newNode;
}

void insertPosition(int pos) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  readStudent(newNode);

  if (pos == 1) {
    newNode->next = head;
    head = newNode;
    return;
  }

  Node *temp = head;
  for (int i = 1; i < pos - 1 && temp != nullptr; i++)
    temp = temp->next;

  if (temp == nullptr) {
    cout << "\nInvalid Position\n";
    free(newNode);
    return;
  }

  newNode->next = temp->next;
  temp->next = newNode;
}

void deletePosition(int pos) {
  if (head == nullptr) {
    cout << "\nList is Empty\n";
    return;
  }

  if (pos == 1) {
    Node *temp = head;
    cout << "\nDeleted Student : " << temp->name << "\n";
    head = head->next;
    free(temp);
    return;
  }

  Node *temp = head;
  for (int i = 1; i < pos - 1 && temp != nullptr; i++)
    temp = temp->next;

  if (temp == nullptr || temp->next == nullptr) {
    cout << "\nInvalid Position\n";
    return;
  }

  Node *deleteNode = temp->next;
  cout << "\nDeleted Student : " << deleteNode->name << "\n";
  temp->next = deleteNode->next;
  free(deleteNode);
}

void deleteBegin() {
  if (head == nullptr) {
    cout << "\nList is Empty\n";
    return;
  }

  Node *temp = head;
  cout << "\nDeleted Student : " << temp->name << "\n";
  head = head->next;
  free(temp);
}

void deleteEnd() {
  if (head == nullptr) {
    cout << "\nList is Empty\n";
    return;
  }

  if (head->next == nullptr) {
    cout << "\nDeleted Student : " << head->name << "\n";
    free(head);
    head = nullptr;
    return;
  }

  Node *temp = head;
  while (temp->next->next != nullptr)
    temp = temp->next;

  cout << "\nDeleted Student : " << temp->next->name << "\n";
  free(temp->next);
  temp->next = nullptr;
}

void searchStudent(int code) {
  Node *temp = head;
  int pos = 1;

  while (temp != nullptr) {
    if (temp->studentCode == code) {
      cout << "\nStudent Found at Position " << pos << "\n";
      cout << "Code   : " << temp->studentCode << "\n";
      cout << "Name   : " << temp->name << "\n";
      cout << "Course : " << temp->course << "\n";
      cout << "Fees   : " << temp->fees << "\n";
      cout << "City   : " << temp->city << "\n";
      return;
    }
    temp = temp->next;
    pos++;
  }

  cout << "\nStudent Not Found\n";
}

void reverseData() {
  Node *prev = nullptr;
  Node *current = head;
  Node *next = nullptr;

  while (current != nullptr) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }

  head = prev;
  cout << "\nStudent List Reversed Successfully\n";
}

int main() {
  int pos, value;

  create();
  display();
  cout << "\nElements Creation Completed\n";

  insertBegining();
  display();
  cout << "\nInsert Beginning Completed\n";

  insertEnd();
  display();
  cout << "\nInsert End Completed\n";

  cout << "\nEnter Position to Insert : ";
  cin >> pos;
  insertPosition(pos);
  display();
  cout << "\nInsert Position Completed\n";

  cout << "\nEnter Position to Delete : ";
  cin >> pos;
  deletePosition(pos);
  display();
  cout << "\nDelete Position Completed\n";

  deleteBegin();
  display();
  cout << "\nDelete Begin Completed\n";

  deleteEnd();
  display();
  cout << "\nDelete End Completed\n";

  cout << "\nEnter Student Code to Search : ";
  cin >> value;
  searchStudent(value);

  reverseData();
  cout << "\nAfter Reverse\n";
  display();
  cout << "NULL\n";

  return 0;
}