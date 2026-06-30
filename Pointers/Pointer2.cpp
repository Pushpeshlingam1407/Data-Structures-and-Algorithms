//TODO: Using a pointer to access and display structure members (arrow operator ->)
#include <bits/stdc++.h>
using namespace std;
int main()
{
    struct
    {

        int code;
        char name[20];
        char city[20];
    } *emp;
    cin >> emp->code >> emp->name >> emp->city;
    cout << "Code: " << emp->code << endl;
    cout << "Name: " << emp->name << endl;
    cout << "City: " << emp->city << endl;
}