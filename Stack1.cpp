//* STACKS

//* Stack Underflow - The case when stack is empty and we try to pop or peek
// from it.
//* Stack Overflow - The case when stack is full and we try to push an element
// into it. ? In Stack, all the operations are performed on the top of the
// stack.
//* Peek - The top most element of the stack.

//* Operations in the Stack:
//? Push - Adding an element to the stack.
//? Pop - Removing the top most element of the stack.
//? isEmpty - Checking if the stack is empty.
//? isFull - Checking if the stack is full.

#include <bits/stdc++.h>
using namespace std;
#define SIZE 10

int stk[SIZE];
int top = -1;

bool isFull() { return top == SIZE - 1; }

bool isEmpty() { return top == -1; }

int peek() {
  if (isEmpty()) {
    cout << "Underflow" << endl;
    return -1;
  }
  return stk[top];
}

void push(int val) {
  if (isFull())
    cout << "Stack Overflow!" << endl;
  else {
    top++;
    stk[top] = val;
    cout << "Inserted: " << val << endl;
  }
}

void pop() {
  if (isEmpty())
    cout << "\nStack Underflow!" << endl;
  else {
    cout << "\nPopped: " << stk[top] << endl;
    top--;
  }
}

void display() {
  if (isEmpty())
    cout << "Stack is empty!" << endl;
  else {
    cout << "Stack elements: ";
    for (int i = 0; i <= top; i++)
      cout << stk[i] << " ";
  }
}

int main() {
  push(12);
  push(231);
  push(232);
  display();
  pop();
  display();
  cout << "\nTop element: " << peek() << endl;
}