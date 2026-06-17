#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node *next;
};

Node *head = nullptr;

void create() {
  Node *newNode, *temp;
  int n;

  cout << "How many nodes: ";
  cin >> n;

  for (int i = 1; i <= n; i++) {
    newNode = new Node;

    cout << "Enter Data: ";
    cin >> newNode->data;

    newNode->next = nullptr;

    if (head == nullptr) {
      head = newNode;
      temp = newNode;
    } else {
      temp->next = newNode;
      temp = newNode;
    }
  }
}

void display() {
  if (head == nullptr) {
    cout << "List Empty\n";
    return;
  }

  Node *temp = head;

  while (temp != nullptr) {
    cout << temp->data << " -> ";
    temp = temp->next;
  }

  cout << "NULL\n";
}

// void insertBeginning() {
//   Node *newNode = new Node;

//   cout << "Enter value for inserting at beginning: ";
//   cin >> newNode->data;

//   newNode->next = head;
//   head = newNode;
// }

// void insertEnd() {
//   Node *newNode = new Node;

//   cout << "Enter value for inserting at end: ";
//   cin >> newNode->data;

//   newNode->next = nullptr;

//   if (head == nullptr) {
//     head = newNode;
//     return;
//   }

//   Node *temp = head;

//   while (temp->next != nullptr) {
//     temp = temp->next;
//   }

//   temp->next = newNode;
// }

// void insertPosition(int pos, int value) {
//   if (pos < 1) {
//     cout << "Invalid Position\n";
//     return;
//   }

//   Node *newNode = new Node;
//   newNode->data = value;

//   if (pos == 1) {
//     newNode->next = head;
//     head = newNode;
//     return;
//   }

//   Node *temp = head;

//   for (int i = 1; i < pos - 1 && temp != nullptr; i++) {
//     temp = temp->next;
//   }

//   if (temp == nullptr) {
//     cout << "Invalid Position\n";
//     delete newNode;
//     return;
//   }

//   newNode->next = temp->next;
//   temp->next = newNode;
// }

// void deletePosition(int pos) {
//   if (head == nullptr) {
//     cout << "List is Empty!\n";
//     return;
//   }

//   if (pos < 1) {
//     cout << "Invalid Position\n";
//     return;
//   }

//   if (pos == 1) {
//     Node *temp = head;
//     head = head->next;
//     delete temp;
//     return;
//   }

//   Node *temp = head;

//   for (int i = 1; i < pos - 1 && temp != nullptr; i++) {
//     temp = temp->next;
//   }

//   if (temp == nullptr || temp->next == nullptr) {
//     cout << "Invalid Position\n";
//     return;
//   }

//   Node *deleteNode = temp->next;
//   temp->next = deleteNode->next;
//   delete deleteNode;
// }

// void deleteBegin() {
//   if (head == nullptr) {
//     cout << "List is Empty!\n";
//     return;
//   }

//   Node *temp = head;
//   head = head->next;
//   delete temp;
// }

// void deleteEnd() {
//   if (head == nullptr) {
//     cout << "List is Empty\n";
//     return;
//   }

//   if (head->next == nullptr) {
//     delete head;
//     head = nullptr;
//     cout << "Last Node Deleted!\n";
//     return;
//   }

//   Node *temp = head;

//   while (temp->next->next != nullptr) {
//     temp = temp->next;
//   }

//   delete temp->next;
//   temp->next = nullptr;

//   cout << "Last Node Deleted!\n";
// }

// void searchData(int key) {
//   Node *temp = head;
//   int pos = 1;

//   while (temp != nullptr) {
//     if (temp->data == key) {
//       cout << key << " found at position " << pos << endl;
//       return;
//     }

//     temp = temp->next;
//     pos++;
//   }

//   cout << "Element Not Found: " << key << endl;
// }

// void reverseData() {
//   Node *prev = nullptr;
//   Node *current = head;
//   Node *next = nullptr;

//   while (current != nullptr) {
//     next = current->next;
//     current->next = prev;
//     prev = current;
//     current = next;
//   }

//   head = prev;
// }

int main() {
  int pos, value;

  create();

  display();

  // cout << "\nElements Creation Completed\n";

  // insertBeginning();
  // display();

  // cout << "\nInsert Beginning Completed\n";

  // insertEnd();
  // display();

  // cout << "\nInsert End Completed\n";

  // cout << "\nEnter position and value to insert: ";
  // cin >> pos >> value;

  // insertPosition(pos, value);
  // display();

  // cout << "\nInsert Position Completed\n";

  // cout << "\nEnter position to delete: ";
  // cin >> pos;

  // deletePosition(pos);
  // display();

  // cout << "\nDelete Position Completed\n";

  // deleteBegin();
  // display();

  // cout << "\nDelete Beginning Completed\n";

  // deleteEnd();
  // display();

  // cout << "\nDelete End Completed\n";

  // cout << "\nEnter Search Element: ";
  // cin >> value;

  // searchData(value);

  // cout << "\nAfter Reverse:\n";
  // reverseData();
  // display();

  // return 0;
}