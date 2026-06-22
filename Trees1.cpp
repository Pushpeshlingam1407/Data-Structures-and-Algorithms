#include <iostream>
using namespace std;

struct Node {
  int data;
  Node *left;
  Node *right;
};

Node *create(int val) {
  Node *newNode = new Node;
  newNode->data = val;
  newNode->left = nullptr;
  newNode->right = nullptr;
  return newNode;
}

Node *insert(Node *root, int val) {
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
void inorder(Node *root) {
  if (root != nullptr) {
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
  }
}

int main() {
  Node *root = nullptr;

  int size;
  cout << "Enter the size of the tree: ";
  cin >> size;

  for (int i = 0; i < size; i++) {
    int val;
    cout << "Enter the value: ";
    cin >> val;
    root = insert(root, val);
  }
  cout << "Inorder traversal: ";
  inorder(root);
}