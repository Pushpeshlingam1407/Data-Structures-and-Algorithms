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

int main(){
  initialize();
}