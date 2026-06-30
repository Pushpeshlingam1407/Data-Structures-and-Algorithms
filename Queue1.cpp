//TODO: Queue implementation using arrays with enqueue, dequeue, peek, and display operations

#include <iostream>
using namespace std;

#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int val) {
  if (rear == SIZE - 1)
    cout << "Stack Overflow" << endl;
  else {
    if (front == -1)
      front = 0;
    rear++;
    queue[rear] == val;
    cout << val << " Inserted" << endl;
  }
}

void dequeue() {
  if (front == -1 || front > rear)
    cout << "Queue Underflow" << endl;
  else {
    cout << "Deleted Element = " << queue[front] << endl;
    front++;
  }
}

void peek() {
  if (front == -1 || front > rear)
    cout << "Queue is Empty" << endl;
  else {
    cout << "Top Element = " << queue[front] << endl;
  }
}

void display() {
  if (front == -1 || front > rear)
    cout << "Queue is Empty" << endl;
  else {
    cout << "Queue Elements: ";
    for (int i = front; i <= rear; i++) {
      cout << queue[i] << " ";
    }
    cout << endl;
  }
}

int main() {
  enqueue(10);
  enqueue(20);
  enqueue(30);
  enqueue(40);
  enqueue(50);

  display();
}