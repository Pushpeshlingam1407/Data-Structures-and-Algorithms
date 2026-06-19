/*
Project: Student Management System (Arrays)
Fields:
Code, Name, Course, Date of Joining, Fees

Functions:
- Insert
- Update
- Delete
- Search
- Display One Record
- Display All Records

Implement using a Array in C++.
*/

#include <iostream>
using namespace std;

struct Student {
  int code;
  string name;
  string course;
  string Doj;
  float fees;
};

void insert(Student arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << "\nEnter Code: ";
    cin >> arr[i].code;
    cout << "Enter Name: ";
    cin >> arr[i].name;
    cout << "Enter Course: ";
    cin >> arr[i].course;
    cout << "Enter Date of Joining: ";
    cin >> arr[i].Doj;
    cout << "Enter Fees: ";
    cin >> arr[i].fees;
  }
}

void display(Student arr[], int n) {
  if (n == 0) {
    cout << "Records Not Found!" << endl;
    return;
  }
  for (int i = 0; i < n; i++) {
    cout << "\nCode: " << arr[i].code << endl;
    cout << "Name: " << arr[i].name << endl;
    cout << "Course: " << arr[i].course << endl;
    cout << "Date of Joining: " << arr[i].Doj << endl;
    cout << "Fees: " << arr[i].fees << endl;
  }
}

int main() {
  int n;
  cout << "Enter the Number of Students: ";
  cin >> n;
  Student arr[n];
  insert(arr, n);
  cout << endl;
  display(arr, n);
}