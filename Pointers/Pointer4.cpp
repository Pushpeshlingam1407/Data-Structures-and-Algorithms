//TODO: Reference variables (aliasing) — demonstrating how references point to the same memory as the original

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a;
    int &b = a;
    cin >> a;
    cout << "Value of a: " << a << "\n";
    cout << "Value of b: " << b << "\n";
    cin >> b;
    cout << "Value of a: " << a << "\n";
    cout << "Value of b: " << b << "\n";
    cout << "Address of a: " << &a << "\n";
    cout << "Address of b: " << &b << "\n";
}