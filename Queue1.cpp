#include <iostream>
using namespace std;

#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int val)
{
    if (rear == SIZE - 1)
        cout << "Stack Overflow" << endl;
    else
    {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] == val;
        cout<<val<<" Inserted"<<endl;
    }
}

void dequeue(){
    if(front==-1 || front>rear) cout<<"Queue Underflow"<<endl;
}
