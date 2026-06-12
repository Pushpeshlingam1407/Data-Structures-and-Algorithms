// Initialization of 2D array
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int arr[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }
}


//* malloc(): Allocates memory but does not initialize it. Returns a `void*` pointer.
//* calloc(): Allocates memory and initializes it to 0. Takes two arguments: number of elements and size of each element. Returns a `void*` pointer.

