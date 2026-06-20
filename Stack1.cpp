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

#include <iostream>
using namespace std;
#define SIZE 10

int arr[SIZE];
int top = -1;
void push(int val) {
  if (top = SIZE - 1)
    cout << "Stack Overflow!";
  else {
    top++;
    stack[top] = val;
    cout << "Inserted values: " << val << endl;
  }
}
int main(){
    push(12);
    push(231);
    push(232);
}