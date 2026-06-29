// TODO: Demonstrates Double Hashing for collision resolution in Hash Tables.
//? What is Double Hashing?
//? When a collision occurs, we use a second hash function to determine the
//? step size for probing.

//* Formula
//? h1(key) = key % SIZE
//? h2(key) = 7 - (key % 7)
//? probe(i) = (h1(key) + i * h2(key)) % SIZE

// ! Time Complexity:
// ! Insert: O(1) average, O(n) worst case (heavy clustering)
// ! Search: O(1) average, O(n) worst case
// ! Delete: O(1) average, O(n) worst case
// ! Space Complexity: O(n) — fixed-size array
// ! Drawback: h2(key) must never return 0, else probe gets stuck on same slot

#include <iostream>
using namespace std;

#define SIZE 10

// -1 = Empty (never used)   -2 = Deleted (tombstone)
int hashTable[SIZE];

void initialize() {
  for (int i = 0; i < SIZE; i++)
    hashTable[i] = -1;
}

int hash1(int key) { return key % SIZE; }
int hash2(int key) { return 7 - (key % 7); } // always in range [1..7], never 0

void insert(int key) {
  int index = hash1(key);
  int step = hash2(key);
  int i = 0;
  while (i < SIZE) {
    int newIndex = (index + i * step) % SIZE;
    if (hashTable[newIndex] == -1 || hashTable[newIndex] == -2) {
      hashTable[newIndex] = key;
      cout << key << " Inserted at index " << newIndex << endl;
      return;
    }
    i++;
  }
  cout << "Hash Table is Full!" << endl;
}

// * Stop at -1 (Empty); don't stop at -2 (tombstone) — key may be beyond it
int search(int key) {
  int index = hash1(key);
  int step = hash2(key);
  int i = 0;
  while (i < SIZE) {
    int newIndex = (index + i * step) % SIZE;
    if (hashTable[newIndex] == key)
      return newIndex;
    if (hashTable[newIndex] == -1)
      return -1;
    i++;
  }
  return -1;
}

// * Use tombstone (-2), NOT -1, to avoid breaking the probe chain
void deleteKey(int key) {
  int index = search(key);
  if (index == -1) {
    cout << "Key " << key << " Not Found!" << endl;
  } else {
    hashTable[index] = -2;
    cout << "Key " << key << " Deleted from index " << index << endl;
  }
}

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
}