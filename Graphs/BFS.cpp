//TODO: Breadth-First Search (BFS) traversal of a graph using adjacency list and a queue

#include <iostream>
using namespace std;

#define SIZE 5

int graph[SIZE][SIZE] = {{0, 1, 1, 0, 0},
                         {1, 0, 0, 1, 0},
                         {1, 0, 0, 0, 1},
                         {0, 1, 0, 0, 1},
                         {0, 0, 1, 1, 0}};

bool visited[SIZE] = {false};
int queue[SIZE];
int front = 0, rear = 0;

void enqueue(int val) { queue[rear++] = val; }
int dequeue() { return queue[front++]; }
bool isEmpty() { return front == rear; }

void BFS(int start) {
  enqueue(start);
  visited[start] = true;

  while (!isEmpty()) {
    int curr = dequeue();
    cout << curr << " ";

    for (int i = 0; i < SIZE; i++) {
      if (graph[curr][i] == 1 && !visited[i]) {
        enqueue(i);
        visited[i] = true;
      }
    }
  }
}

int main() {
  cout << "BFS Traversal: ";
  BFS(0);
  cout << endl;
  return 0;
}
