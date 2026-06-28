// * Demonstration of Linear Probing in Hash Tables
//? What is Linear Probing?
//? When a collision occurs, we check the very next slot (index + 1, index + 2 ...)
//? It is the simplest open addressing collision resolution technique
//? Main drawback: PRIMARY CLUSTERING — long runs of occupied slots form over time

// ! Time Complexity:
// ! Insert: O(1) average, O(n) worst case (heavy clustering)
// ! Search: O(1) average, O(n) worst case
// ! Delete: O(1) average, O(n) worst case
// ! Space Complexity: O(n) — fixed-size array

// TODO: Add load factor tracking (warn if > 70% full to avoid clustering)
// TODO: Implement rehashing / table resizing when load factor is exceeded
// TODO: Visualize the clustering effect with a graphical display

#include <iostream>
using namespace std;

// * Fixed capacity of the hash table
#define SIZE 10

// * Sentinel values used as slot markers:
//   -1 = Empty   → slot was never used
//   -2 = Deleted → tombstone, slot was used but key was removed
int hashTable[SIZE];

// * Initializes all hash table slots to -1 (Empty) before use
void initialize() {
  for (int i = 0; i < SIZE; i++) {
    hashTable[i] = -1;
  }
}

// * Insert: Places key into the table using linear probing
//? Why (index + 1) % SIZE?  → Wraps around to slot 0 after slot SIZE-1
//! WARNING: Linear probing causes PRIMARY CLUSTERING
//!          Long chains of occupied slots form, degrading performance to O(n)
void insert(int key) {
  int index = key % SIZE;   // Hash function: simple modulo
  int start = index;         // * Remember start to detect full table (full cycle)

  // * Skip over occupied slots — probe one step at a time
  while (hashTable[index] != -1 && hashTable[index] != -2) {
    index = (index + 1) % SIZE;   // Linear probe: move to next slot

    //! If we've looped back to start, the table is completely full
    if (index == start) {
      cout << "Hash Table is Full!" << endl;
      return;
    }
  }

  // * Insert into the first Empty or Deleted slot found
  hashTable[index] = key;
  cout << key << " inserted at index " << index << endl;
}

// * Search: Finds key by following the same linear probe sequence as insert
//? Why stop at -1 (Empty) but NOT at -2 (Deleted)?
//? -1 means no key could ever have been inserted past this point
//? -2 (tombstone) means a key WAS here before — we must keep probing past it
int search(int key) {
  int index = key % SIZE;
  int start = index;

  while (hashTable[index] != -1) {
    if (hashTable[index] == key)
      return index;   // * Key found — return its index

    index = (index + 1) % SIZE;

    if (index == start)
      break;   // * Completed full cycle, key not present
  }

  return -1;   // * Key not found
}

// * Delete: Uses tombstone (-2) strategy to preserve probe chain integrity
//! CRITICAL: NEVER set a deleted slot back to -1 (Empty)!
//!           Doing so would break the probe chain — future searches for keys
//!           that were inserted AFTER this slot would terminate too early
//? Tombstone (-2) tells search: "keep probing, something was here before"
//? Tombstone (-2) tells insert: "you can reuse this slot"
void deleteKey(int key) {
  int index = search(key);
  if (index == -1) {
    cout << "Key " << key << " Not Found!" << endl;
  } else {
    hashTable[index] = -2;   // * Mark as tombstone (logically deleted)
    cout << "Key " << key << " Deleted from Index " << index << endl;
  }
}

// * Display: Prints the full hash table showing slot states
void display() {
  cout << "\nIndex | Value\n";
  cout << "------+-------\n";
  for (int i = 0; i < SIZE; i++) {
    if (hashTable[i] == -1)
      cout << "  " << i << "   | Empty\n";          // * Never-used slot
    else if (hashTable[i] == -2)
      cout << "  " << i << "   | Deleted\n";        // * Tombstone slot
    else
      cout << "  " << i << "   | " << hashTable[i] << "\n";
  }
  cout << endl;
}

int main() {
  initialize();   // * Must be called first to set all slots to Empty (-1)

  int n, key, choice;

  cout << "Enter Number of Keys to Insert: ";
  cin >> n;
  for (int i = 0; i < n; i++) {
    cout << "Enter Key " << i + 1 << ": ";
    cin >> key;
    insert(key);
  }

  display();

  // * Menu-driven interface: Search, Delete, Display, Exit
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
      display();   // * Show updated table after deletion

    } else if (choice == 3) {
      display();
    }

  } while (choice != 0);

  return 0;
}