//TODO: Nested structures — struct within a struct with direct initialization (static allocation)

#include <bits/stdc++.h>
using namespace std;

struct student
{
    int code;
    string name;
    string desig;
    struct
    {
        string area;
        string city;
        string state;
    } add;
} emp = {
    100,
    "Pushpesh",
    "DSA",
    {"MM Road",
     "Ongole",
     "AP"}};
int main()
{
    cout << emp.code << " " << emp.name << " " << emp.desig << "\n";
    cout << emp.add.area << " " << emp.add.city << " " << emp.add.state << "\n";
}