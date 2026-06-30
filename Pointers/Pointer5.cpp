//TODO: Variable references in C++ — demonstrating reference syntax and behavior

#include <bits/stdc++.h>
using namespace std;

int main(){
    int a[3][3], r = 3, c = 3;

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> *(*(a + i) + j);
        }
    }

    cout << "\nValue\tAddress\n";
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cout << *(*(a + i) + j) << "\t" << (*(a + i) + j) << endl;
        }
    }

    return 0;
}