#include <bits/stdc++.h>
using namespace std;

#define SIZE 5

int graph[SIZE][SIZE] = {{0, 1, 1, 0, 0},
                         {1, 0, 0, 1, 0},
                         {1, 0, 0, 0, 1},
                         {0, 1, 0, 0, 1},
                         {0, 0, 1, 1, 0}};

bool visited[SIZE] = {false};

void BFS(int start) {
  queue<int> q;
  q.push(start);
  visited[start] = true;

  while (!q.empty()) {
    int curr = q.front();
    q.pop();
    cout << curr << " ";

    for (int i = 0; i < SIZE; i++) {
      if (graph[curr][i] == 1 && !visited[i]) {
        q.push(i);
        visited[i] = true;
      }
    }
  }
}

int main() {
  cout << "BFS Traversal: ";
  BFS(0);
  cout << endl;
}