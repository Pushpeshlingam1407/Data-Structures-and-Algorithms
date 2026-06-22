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

struct Node *insert(struct Node *root, int val) {
  if (root == nullptr) {
    return create(val);
  }
  if (val < root->data) {
    root->left = insert(root->left, val);
  } else if (val > root->data) {
    root->right = insert(root->right, val);
  }
  return root;
}
int main() {
  struct Node *root = nullptr;
  int size;
  cin >> size;
  for (int i = 0; i < size; i++) {
    int val;
    cin >> val;
    root = create(root, val);
  }
}