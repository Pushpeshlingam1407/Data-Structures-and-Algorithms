#include <iostream>
using namespace std;

#define SIZE 10

int hashTable[SIZE];

void insert(int key) {
  int index = key % SIZE;
  cout << "\nKey: " << index << " Value " << key << endl;
}

int display() {
  cout << "Hash Table Elements: ";
  for (int i = 0; i < SIZE; i++) {
    cout << hashTable[i] << " ";
  }
  cout << endl;
}

int search(int key) {
  int index = key % SIZE;
  if (hashTable[index] == key)
    return index;
  else
    return -1;
}

int main() {
  int n, key;
  cout << "Enter Number of Keys: ";
  cin >> n;

  for (int i = 0; i < n; i++) {
    cout << "Enter Key " << i + 1 << ": ";
    cin >> key;
    insert(key);
    display();
  }
  cout << endl;
  cout << "Enter Key to Search: ";
  cin >> key;
  if (search(key) != -1) {
    cout << "Element Found at Index " << search(key) << endl;
  } else {
    cout << "Element Not Found" << endl;
  }
}