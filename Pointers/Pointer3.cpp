//TODO: Array input/output using pointers — printing values and memory addresses

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int a[n];
    int *p = a;

    for (int i = 0; i < n; i++)
        cin >> *(p + i);

    for (int i = 0; i < n; i++)
        cout << *(p + i) << "\t" << (p + i) << "\n";

    return 0;
}