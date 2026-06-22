#include <iostream>
using namespace std;

struct Node {
  int data;
  struct Node *left;
  struct Node *right;
};
struct Node *create() {
  struct Node *newNode;
  newNode = (struct Node *)malloc(sizeof(struct Node));
  cout << "Enter Value: ";
  cin >> newNode->data;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

int main() { struct Node *root = nullptr; }