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

//* Brute Force Approach!!

/*
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
    cout << "\nEnter Code of Student " << i + 1 << ": ";
    cin >> arr[i].code;
    cout << "Enter Name of Student " << i + 1 << ": ";
    cin >> arr[i].name;
    cout << "Enter Course of Student " << i + 1 << ": ";
    cin >> arr[i].course;
    cout << "Enter Date of Joining of Student " << i + 1 << ": ";
    cin >> arr[i].Doj;
    cout << "Enter Fees of Student " << i + 1 << ": ";
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

void update(Student arr[], int n) {
  int code;
  cout << "Enter the code to update: ";
  cin >> code;
  for (int i = 0; i < n; i++) {
    if (arr[i].code == code) {
      cout << "Enter new name: " << endl;
      cin >> arr[i].name;
      cout << "ENter new course: " << endl;
      cin >> arr[i].course;
      cout << "Enter new Doj: " << endl;
      cin >> arr[i].Doj;
      cout << "Enter new Fees: " << endl;
      cin >> arr[i].fees;
      return;
    }
  }
  cout << "Not Found!" << endl;
}

void remove(Student arr[], int n) {
  int code;
  cin >> code;
  for (int i = 0; i < n; i++) {
    if (arr[i].code == code) {
      arr[i].code = -1;
      arr[i].name = "";
      arr[i].course = "";
      arr[i].Doj = "";
      arr[i].fees = 0;
      cout << "Record Deleted Successfully!" << endl;
      return;
    }
  }
  cout << "Not Found!" << endl;
}

void search(Student arr[], int n) {
  int code;
  cin >> code;
  for (int i = 0; i < n; i++) {
    if (arr[i].code == code) {
      cout << "Code: " << arr[i].code << endl;
      cout << "Name: " << arr[i].name << endl;
      cout << "Course: " << arr[i].course << endl;
      cout << "Date of Joining: " << arr[i].Doj << endl;
      cout << "Fees: " << arr[i].fees << endl;
      return;
    }
  }
  cout << "Not Found!" << endl;
}

void displayOne(Student arr[], int n) {
  int code;
  cin >> code;
  for (int i = 0; i < n; i++) {
    if (arr[i].code == code) {
      cout << "Code: " << arr[i].code << endl;
      cout << "Name: " << arr[i].name << endl;
      cout << "Course: " << arr[i].course << endl;
      cout << "Date of Joining: " << arr[i].Doj << endl;
      cout << "Fees: " << arr[i].fees << endl;
      return;
    }
  }
  cout << "Not Found!" << endl;
}
int main() {
  int n;
  cout << "Enter the Number of Students: ";
  cin >> n;
  Student arr[n];
  insert(arr, n);
  cout << endl;
  display(arr, n);
  update(arr, n);
  cout << endl;
  display(arr, n);
  cout << "Enter Code to Display One: ";
  displayOne(arr, n);
  cout << "Enter Code to Search: ";
  search(arr, n);
  cout << "Enter Code to Delete: ";
  remove(arr, n);
  cout << endl;
  display(arr, n);
}

*/

//? Better approach
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
    cout << "\nEnter Code of Student " << i + 1 << ": ";
    cin >> arr[i].code;
    cout << "Enter Name of Student " << i + 1 << ": ";
    cin >> arr[i].name;
    cout << "Enter Course of Student " << i + 1 << ": ";
    cin >> arr[i].course;
    cout << "Enter Date of Joining of Student " << i + 1 << ": ";
    cin >> arr[i].Doj;
    cout << "Enter Fees of Student " << i + 1 << ": ";
    cin >> arr[i].fees;
  }
}

void printAll(Student arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << "\nCode: " << arr[i].code << endl;
    cout << "Name: " << arr[i].name << endl;
    cout << "Course: " << arr[i].course << endl;
    cout << "Date of Joining: " << arr[i].Doj << endl;
    cout << "Fees: " << arr[i].fees << endl;
  }
}
void display(Student arr[], int n) {
  if (n == 0) {
    cout << "No Records Found!\n";
    return;
  }
  printAll(arr, n);
}
// void update(Student arr[], int n){

// }
// void remove(Student arr[], int n){

// }
// void search(Student arr[], int n){

// }
// void displayOne(Student arr[], int n){

// }
int main() {
  int n;
  cout << "Enter Number of Students: ";
  cin >> n;
  Student arr[n];
  insert(arr, n);
  display(arr, n);
}