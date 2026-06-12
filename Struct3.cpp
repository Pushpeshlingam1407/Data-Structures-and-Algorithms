//* Dynamic Initialization of an array of structures

#include <bits/stdc++.h>
using namespace std;

struct student
{
    int code;
    string name;
    string course;
};

int main()
{
    student st[100];
    int n;

    cout << "Enter number of students: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> st[i].code >> st[i].name >> st[i].course;
    }

    cout << "\n";
    cout << left
         << setw(10) << "Code"
         << setw(15) << "Name"
         << setw(15) << "Course" << "\n";

    for (int i = 0; i < n; i++)
    {
        cout << setw(10) << st[i].code
             << setw(15) << st[i].name
             << setw(15) << st[i].course << "\n";
    }

    return 0;
}