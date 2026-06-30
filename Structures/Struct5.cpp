// Example of nested structure initialization and usage (static memory allocation)

#include <bits/stdc++.h>
using namespace std;
struct Employee
{
    int code;
    char name[100];
    char desig[100];
    struct
    {
        char area[100];
        char city[100];
        char state[100];
    } add;
};
int main()
{
    struct Employee emp;
    cin >> emp.code >> emp.name >> emp.desig;
    cin >> emp.add.area >> emp.add.city >> emp.add.state;
    cout << emp.code << " " << emp.name << " " << emp.desig << "\n";
    cout << emp.add.area << " " << emp.add.city << " " << emp.add.state << "\n";
}