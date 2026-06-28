#include <iostream>
using namespace std;

#define SIZE 10

int hashTable[SIZE];

void initialize() {
  for (int i = 0; i < SIZE; i++)
    hashTable[i] = -1;
}

void insert(int key) {
  int index = key % SIZE;
  int i = 0;
  while (i < SIZE) {
    int newIndex = (index + i * i) % SIZE;
    if (hashTable[newIndex] == -1 || hashTable[newIndex] == -2) {
      hashTable[newIndex] = key;
      cout << key << " Inserted at index " << newIndex << endl;
      return;
    }
    i++;
  }
  cout << "Hash Table is full!" << endl;
}

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

void deleteKey(int key) {
  int index = key % SIZE;
  int i = 0;
  while (i < SIZE) {
    int newIndex = (index + i * i) % SIZE;
    if (hashTable[newIndex] == key) {
      hashTable[newIndex] = -2;
      cout << "Key " << key << " Deleted from index " << newIndex << endl;
      return;
    }
    i++;
  }
  cout << "Key " << key << " Not Found!" << endl;
}

void display() {
  cout << "\nIndex | Value" << endl;
  cout << "------+-------" << endl;
  for (int i = 0; i < SIZE; i++) {
    if (hashTable[i] == -1)
      cout << "  " << i << "   | Empty" << endl;
    else if (hashTable[i] == -2)
      cout << "  " << i << "   | Deleted" << endl;
    else
      cout << "  " << i << "   | " << hashTable[i] << endl;
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
      search(key);

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