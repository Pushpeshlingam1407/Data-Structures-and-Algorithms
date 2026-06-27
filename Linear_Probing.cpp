#include <iostream>
using namespace std;

#define SIZE 10

// -1 = Empty, -2 = Deleted (tombstone)
int hashTable[SIZE];

// Initialize Hash Table
void initialize() {
  for (int i = 0; i < SIZE; i++) {
    hashTable[i] = -1;
  }
}

// Insert with Linear Probing
void insert(int key) {
  int index = key % SIZE;
  int start = index;

  while (hashTable[index] != -1 && hashTable[index] != -2) {
    index = (index + 1) % SIZE;
    if (index == start) {
      cout << "Hash Table is Full!" << endl;
      return;
    }
  }

  hashTable[index] = key;
  cout << key << " inserted at index " << index << endl;
}

// Search with Linear Probing
int search(int key) {
  int index = key % SIZE;
  int start = index;

  while (hashTable[index] != -1) {
    if (hashTable[index] == key)
      return index;

    index = (index + 1) % SIZE;

    if (index == start)
      break;
  }

  return -1;
}

// Delete with Tombstone (-2) to preserve probe chains
void deleteKey(int key) {
  int index = search(key);
  if (index == -1) {
    cout << "Key " << key << " Not Found!" << endl;
  } else {
    hashTable[index] = -2; // Mark as deleted (tombstone)
    cout << "Key " << key << " Deleted from Index " << index << endl;
  }
}

// Display Hash Table
void display() {
  cout << "\nIndex | Value\n";
  cout << "------+-------\n";
  for (int i = 0; i < SIZE; i++) {
    if (hashTable[i] == -1)
      cout << "  " << i << "   | Empty\n";
    else if (hashTable[i] == -2)
      cout << "  " << i << "   | Deleted\n";
    else
      cout << "  " << i << "   | " << hashTable[i] << "\n";
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

  cout << "1. Search  2. Delete  3. Display  0. Exit\n";
  do {
    cout << "\nEnter Choice: ";
    cin >> choice;

    if (choice == 1) {
      cout << "Enter Key to Search: ";
      cin >> key;
      int result = search(key);
      if (result != -1)
        cout << "Key " << key << " Found at Index " << result << endl;
      else
        cout << "Key " << key << " Not Found!" << endl;

    } else if (choice == 2) {
      cout << "Enter Key to Delete: ";
      cin >> key;
      deleteKey(key);
      display();

    } else if (choice == 3) {
      display();
    }

  } while (choice != 0);

  return 0;
}