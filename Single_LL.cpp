#include <iostream>
using namespace std;

struct Node {
  int data;
  struct Node *next;
};
struct Node *head = nullptr;

void create() {
  struct Node *newNode, *temp;
  int n, i;
  cout << "Enter the Number of Nodes: ";
  cin >> n;
  for (int i = 1; i <= n; i++) {
    newNode = (struct Node *)malloc(sizeof(struct Node));
    cout << "Enter Elements: ";
    cin >> newNode->data;
    newNode->next = nullptr; // Assign Null Initially
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
  struct Node *temp;
  if (head == nullptr) {
    cout << "List is Empty!";
    return;
  }
  temp = head;
  while (temp != nullptr) {
    cout << temp->data << " -> ";
    temp = temp->next;
  }
  cout << "null";
}
void insertBeg(){
  
}
int main() {
  create();
  display();
}