//TODO: Initialization of an array of structures

#include <bits/stdc++.h>
using namespace std;

struct student {
  int code;
  string name;
  string course;
};

int main() {
  student st[] = {{232, "David", "OOPs"}, {231, "Pushpesh", "DSA"}};

  cout << st[0].code << " " << st[0].name << " " << st[0].course << "\n";
  cout << st[1].code << " " << st[1].name << " " << st[1].course << "\n";

  return 0;
}