#include <iostream>
using namespace std;

#define SIZE 10

int hashTable[SIZE];

void insert(int key) {
  int index = key % SIZE;
  cout << "\nKey: " << index << " Value " << key << endl;
}

int main() {
  int n, key;
  cout << "Enter Number of Keys: ";
  cin >> n;

  for (int i = 0; i < n; i++) {
    cout << "Enter Key " << i + 1 << ": ";
    cin >> key;
    insert(key);
  }
}