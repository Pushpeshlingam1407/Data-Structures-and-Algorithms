// * Demonstration of Quadratic Probing in Hash Tables
//? What is Quadratic Probing?
//? Instead of checking next slot (linear), it checks slots at i² distance
//? Probe sequence: h(k), h(k)+1, h(k)+4, h(k)+9, h(k)+16 ...
//? This reduces PRIMARY CLUSTERING seen in linear probing

// ! Time Complexity:
// ! Insert: O(1) average, O(n) worst case (table almost full)
// ! Search: O(1) average, O(n) worst case
// ! Delete: O(1) average, O(n) worst case
// ! Space Complexity: O(n) — fixed array of SIZE elements

// TODO: Add load factor check to warn when table > 50% full
// TODO: Implement rehashing when table is too full
// TODO: Add support for string keys using a custom hash function

#include <iostream>
using namespace std;

// * SIZE defines the total capacity of the hash table
#define SIZE 10

// * Sentinel values:
//   -1 = Empty slot (never used)
//   -2 = Deleted slot (tombstone — was used but now removed)
int hashTable[SIZE];

// * Initializes all slots to -1 (Empty) before first use
void initialize() {
  for (int i = 0; i < SIZE; i++)
    hashTable[i] = -1;
}

// * Insert: Places key using quadratic probing
//? Why i*i? Quadratic steps reduce clustering compared to linear (i)
//! WARNING: If table load > 50%, quadratic probing may fail to find a slot
//!          even when empty slots exist — not all slots are guaranteed to be
//!          visited
void insert(int key) {
  int index = key % SIZE; // Hash function: simple modulo
  int i = 0;

  while (i < SIZE) {
    int newIndex = (index + i * i) % SIZE; // Quadratic probe: index + i²

    // * Accept slot if Empty (-1) or previously Deleted (-2)
    if (hashTable[newIndex] == -1 || hashTable[newIndex] == -2) {
      hashTable[newIndex] = key;
      cout << key << " Inserted at index " << newIndex << endl;
      return;
    }
    i++;
  }

  //! Table is full — no valid slot found after SIZE probes
  cout << "Hash Table is full!" << endl;
}

// * Search: Finds key using same quadratic probe sequence as insert
//? Why follow the same probe sequence?
//? The key was inserted along this path, so we must search along it too
//! Stops early at -1 (Empty) since key couldn't have jumped over a never-used
//! slot
void search(int key) {
  int index = key % SIZE;
  int i = 0;

  while (i < SIZE) {
    int newIndex = (index + i * i) % SIZE;

    if (hashTable[newIndex] == key) {
      cout << "Key " << key << " Found at index " << newIndex << endl;
      return;
    }
    i++;
  }

  cout << "Key " << key << " Not Found!" << endl;
}

// * Delete: Marks slot as -2 (Deleted/Tombstone) instead of -1 (Empty)
//! CRITICAL: Never set deleted slot to -1 (Empty)!
//!           That would break the probe chain for other keys that were
//!           inserted after this slot was occupied
//? Why use tombstone (-2)?
//? Future inserts can reuse -2 slots, but searches must not stop at them
void deleteKey(int key) {
  int index = key % SIZE;
  int i = 0;

  while (i < SIZE) {
    int newIndex = (index + i * i) % SIZE;

    if (hashTable[newIndex] == key) {
      hashTable[newIndex] = -2; // * Mark as tombstone (logically deleted)
      cout << "Key " << key << " Deleted from index " << newIndex << endl;
      return;
    }
    i++;
  }

  cout << "Key " << key << " Not Found!" << endl;
}

// * Display: Prints every slot — Empty, Deleted, or occupied
void display() {
  cout << "\nIndex | Value" << endl;
  cout << "------+-------" << endl;
  for (int i = 0; i < SIZE; i++) {
    if (hashTable[i] == -1)
      cout << "  " << i << "   | Empty" << endl;
    else if (hashTable[i] == -2)
      cout << "  " << i << "   | Deleted" << endl; // * Tombstone slot
    else
      cout << "  " << i << "   | " << hashTable[i] << endl;
  }
  cout << endl;
}

int main() {
  initialize(); // * Must initialize before any operations

  int n, key, choice;

  cout << "Enter Number of Keys to Insert: ";
  cin >> n;
  for (int i = 0; i < n; i++) {
    cout << "Enter Key " << i + 1 << ": ";
    cin >> key;
    insert(key);
  }

  display();

  // * Menu-driven interface for Search, Delete, Display
  cout << "1. Search  2. Delete  3. Display  0. Exit\n";
  do {
    cout << "\nEnter Choice: ";
    cin >> choice;

    if (choice == 1) {
      cout << "Enter Key to Search: ";
      cin >> key;
      search(key);

    } else if (choice == 2) {
      cout << "Enter Key to Delete: ";
      cin >> key;
      deleteKey(key);
      display(); // * Show updated table after deletion

    } else if (choice == 3) {
      display();
    }

  } while (choice != 0);
}