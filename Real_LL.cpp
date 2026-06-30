//TODO: Singly Linked List with real-world insert, delete, and traversal operations

#include <iostream>
#include <string>
using namespace std;

struct Student {
  int code;
  string name;
  string course;
  string doj;
  float fees;
  Student *next;
};

Student *head = nullptr;

void create() {
  Student *newStudent;
  Student *temp = nullptr;
  int n;

  cout << "Enter the Number of Students: ";
  cin >> n;

  for (int i = 1; i <= n; i++) {
    newStudent = new Student;

    cout << "\nStudent " << i << endl;

    cout << "Enter Code   : ";
    cin >> newStudent->code;

    cin.ignore();

    cout << "Enter Name   : ";
    getline(cin, newStudent->name);

    cout << "Enter Course : ";
    getline(cin, newStudent->course);

    cout << "Enter DOJ    : ";
    getline(cin, newStudent->doj);

    cout << "Enter Fees   : ";
    cin >> newStudent->fees;

    newStudent->next = nullptr;

    if (head == nullptr) {
      head = newStudent;
      temp = newStudent;
    } else {
      temp->next = newStudent;
      temp = newStudent;
    }
  }
}

void display() {
  if (head == nullptr) {
    cout << "\nList is Empty!\n";
    return;
  }

  Student *temp = head;

  cout << "\nStudent Records:\n\n";

  while (temp != nullptr) {
    cout << "[" << temp->code << " | " << temp->name << " | " << temp->course
         << " | " << temp->doj << " | " << temp->fees << "] -> ";

    temp = temp->next;
  }

  cout << "NULL\n";
}

void freeList() {
  Student *temp;

  while (head != nullptr) {
    temp = head;
    head = head->next;
    delete temp;
  }
}

int main() {
  create();

  cout << "\nOriginal List:\n";
  display();

  freeList();
}