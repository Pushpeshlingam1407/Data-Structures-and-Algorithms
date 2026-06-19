/*
=========================================================
        STUDENT MANAGEMENT SYSTEM USING LINKED LIST
=========================================================

Objective:
Implement a Student Management System using a Singly
Linked List to store and manage student records.

Student Information:
- Student Code
- Student Name
- Course
- Date of Joining
- Fees

Features:
1. Insert a new student record
2. Update an existing student record
3. Delete a student record
4. Search for a student by code
5. Display a specific student record
6. Display all student records

Note:
- Each node stores one student record.
- Student Code is used as a unique identifier.
- All operations must be performed using linked list traversal.

=========================================================
*/

#include <iostream>
using namespace std;

struct Node {
  int code;
  string name;
  string course;
  string doj;
  float fees;
  struct Node *next;
};
struct Node *head = nullptr;

void create(){
    
}