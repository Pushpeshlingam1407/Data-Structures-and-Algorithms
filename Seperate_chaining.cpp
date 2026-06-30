// TODO: Implemention of Separate Chaining
// ? A separate chaining is a Collision Resolution Technique used in Hash Tables
// ? It is a method of storing multiple values in the same index of the hash
// table ? The values are stored in a linked list at the index

//! Formula
//? h(key) = key % SIZE

//! Time Complexity:
//! Insert: O(1) Average, O(n) worst case
//! Search: O(1) Average, O(n) worst case
//! Delete: O(1) Average, O(n) worst case
//! Space Complexity: O(n)

#include <iostream>
using namespace std;

#define SIZE 10

struct Node {
  int data;
  Node *next;
};

Node *hashTable[SIZE];

void initialize() {
  for (int i = 0; i < SIZE; i++)
    hashTable[i] = nullptr;
}

void insert(int key) {
  int index = key % SIZE;
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = key;
  newNode->next = NULL;
  if (hashTable[index] == NULL) {
    hashTable[index] = newNode;
  } else {
    Node *temp = hashTable[index];
    while (temp->next != nullptr)
      temp = temp->next;
    temp->next = newNode;
  }
  cout << key << " Inserted at Index " << index << endl;
}

void search(int key) {
  int index = key % SIZE;
  Node *temp = hashTable[index];
  while (temp != nullptr && temp->data != key) {
    temp = temp->next;
  }
  if (temp != nullptr)
    cout << key << " is present at Index " << index << endl;
  else
    cout << key << " is not present at Index " << index << endl;
}

void display() {
  for (int i = 0; i < SIZE; i++) {
    cout << "Index " << i << ": ";
    Node *temp = hashTable[i];
    while (temp != nullptr) {
      cout << temp->data << " -> ";
      temp = temp->next;
    }
    cout << "NULL" << endl;
  }
}

int main() {
  initialize();
  insert(123);
  insert(231);
  insert(223);
  insert(232);
  insert(185);
  insert(229);
  insert(244);
  insert(215);
  display();
  search(231);
  search(230);
}