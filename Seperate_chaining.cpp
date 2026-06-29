// TODO: Implemention of Separate Chaining
//? A separate chaining is a Collision Resolution Technique used in Hash Tables
//? It is a method of storing multiple values in the same index of the hash table 
//? The values are stored in a linked list at the index

//! Formula
//? h(key) = key % SIZE

//! Time Complexity:
//! Insert: O(1) Average
//! Search: O(1) Average
//! Delete: O(1) Average
//! Space Complexity: O(n)

#include <iostream>
using namespace std;

#define SIZE 10

int hashTable[SIZE];

void initialize() {
  for (int i = 0; i < SIZE; i++) {
    hashTable[i] = -1;
  }
}

int hashFunction(int key) { return key % SIZE; }

void insert(int key) {
  int index = hashFunction(key);
  if (hashTable[index] == -1) {
    hashTable[index] = key;
    cout << key << " Inserted at index " << index << endl;
  } else {
    cout << "Collision at index " << index << " for key " << key << endl;
  }
}

void display() {
  cout << "Hash Table Values:" << endl;
  for (int i = 0; i < SIZE; i++) {
    if (hashTable[i] == -1) {
      cout << i << " --> Empty " << endl;
    } else {
      cout << i << " --> " << hashTable[i] << endl;
    }
  }
}

int main() {
  initialize();
  insert(12);
  insert(22);
  insert(32);
  insert(42);
  insert(52);
  insert(62);
  insert(72);
  insert(82);
  insert(92);
  insert(102);
  display();
  return 0;
}