// TODO: Linear Probing — Open Addressing Collision Resolution
//? On collision, probe next slot: (h(key) + i) % SIZE  (i = 1, 2, 3...)
//? Drawback: PRIMARY CLUSTERING — long chains of occupied slots degrade perf

// * Formula:  probe(i) = (h1(key) + i) % SIZE

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

#define SIZE 10

// -1 = Empty (never used)   -2 = Deleted (tombstone)
int hashTable[SIZE];

void initialize() {
  for (int i = 0; i < SIZE; i++) {
    hashTable[i] = -1;
  }
}

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

// * Stop at -1 (Empty) — no key could exist past here
// * Don't stop at -2 (Deleted/tombstone) — a key may have been inserted beyond it
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

// * Use tombstone (-2), NOT -1, to avoid breaking the probe chain
void deleteKey(int key) {
  int index = search(key);
  if (index == -1) {
    cout << "Key " << key << " Not Found!" << endl;
  } else {
    hashTable[index] = -2;
    cout << "Key " << key << " Deleted from Index " << index << endl;
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