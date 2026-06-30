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

// * Search returns the index if found, -1 otherwise
int search(int key) {
  int index = key % SIZE;
  Node *temp = hashTable[index];
  while (temp != nullptr) {
    if (temp->data == key)
      return index;
    temp = temp->next;
  }
  return -1;
}

// * Delete a key from the linked list at its hash index
void deleteKey(int key) {
  int index = key % SIZE;
  Node *temp = hashTable[index];
  Node *prev = nullptr;

  while (temp != nullptr && temp->data != key) {
    prev = temp;
    temp = temp->next;
  }

  if (temp == nullptr) {
    cout << "Key " << key << " Not Found!" << endl;
    return;
  }

  if (prev == nullptr)
    hashTable[index] = temp->next; // deleting head node
  else
    prev->next = temp->next;

  free(temp);
  cout << "Key " << key << " Deleted from Index " << index << endl;
}

void display() {
  cout << "\nIndex | Chain\n";
  cout << "------+---------------------------\n";
  for (int i = 0; i < SIZE; i++) {
    cout << "  " << i << "   | ";
    Node *temp = hashTable[i];
    if (temp == nullptr) {
      cout << "NULL";
    } else {
      while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
      }
      cout << "NULL";
    }
    cout << "\n";
  }
  cout << endl;
}

int main() {
  initialize();

  int n, key, choice;

  cout << "Enter Number of Keys to Insert: ";
  cin >> n;
  for (int i = 0; i < n; i++) {
    cout << "Enter Key " << i + 1 << ": ";
    cin >> key;
    insert(key);
  }

  display();

  cout << "1. Insert  2. Search  3. Delete  4. Display  0. Exit\n";
  do {
    cout << "\nEnter Choice: ";
    cin >> choice;

    if (choice == 1) {
      cout << "Enter Key to Insert: ";
      cin >> key;
      insert(key);
      display();

    } else if (choice == 2) {
      cout << "Enter Key to Search: ";
      cin >> key;
      int result = search(key);
      if (result != -1)
        cout << "Key " << key << " Found at Index " << result << endl;
      else
        cout << "Key " << key << " Not Found!" << endl;

    } else if (choice == 3) {
      cout << "Enter Key to Delete: ";
      cin >> key;
      deleteKey(key);
      display();

    } else if (choice == 4) {
      display();
    }

  } while (choice != 0);

  return 0;
}