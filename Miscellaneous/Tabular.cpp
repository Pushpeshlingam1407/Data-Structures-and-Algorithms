//TODO: Tabular output formatting using iomanip — displaying data in aligned columns

#include <iomanip>
#include <iostream>

using namespace std;

int main() {
  int students[100][4];
  int i = 0, code, m, p, c, l;

  do {
    cout << "Enter Student Code: ";
    cin >> code;

    if (code > 0) {
      cout << "Enter Maths, Physics, Chemistry Marks: ";
      cin >> m >> p >> c;

      students[i][0] = code;
      students[i][1] = m;
      students[i][2] = p;
      students[i][3] = c;

      i++;
    }

  } while (code > 0);

  l = i;

  cout << "\nCode\tMaths\tPhysics\tChemistry\n";

  for (i = 0; i < l; i++) {
    cout << students[i][0] << "\t" << students[i][1] << "\t" << students[i][2]
         << "\t" << students[i][3] << endl;
  }

  cout << "\nEnter Search Code: ";
  cin >> code;

  bool found = false;

  for (i = 0; i < l; i++) {
    if (students[i][0] == code) {
      cout << "\nStudent Found\n";
      cout << "Code: " << students[i][0] << endl;
      cout << "Maths: " << students[i][1] << endl;
      cout << "Physics: " << students[i][2] << endl;
      cout << "Chemistry: " << students[i][3] << endl;

      found = true;
      break;
    }
  }

  if (!found) {
    cout << "Student Code Not Found." << endl;
  }

  return 0;
}