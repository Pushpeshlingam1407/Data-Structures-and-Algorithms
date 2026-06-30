//TODO: Depth-First Search (DFS) traversal using STL stack and visited array

#include <bits/stdc++.h>
using namespace std;

#define SIZE 5

int graph[SIZE][SIZE] = {{0, 1, 1, 0, 0},
                         {1, 0, 0, 1, 0},
                         {1, 0, 0, 0, 1},
                         {0, 1, 0, 0, 1},
                         {0, 0, 1, 1, 0}};

bool visited[SIZE] = {false};

void DFS(int node) {
  visited[node] = true;
  cout << node << " ";

  for (int i = 0; i < SIZE; i++) {
    if (graph[node][i] == 1 && !visited[i]) {
      DFS(i);
    }
  }
}

int main() {
  cout << "DFS Traversal: ";
  DFS(0);
  cout << endl;
  return 0;
}