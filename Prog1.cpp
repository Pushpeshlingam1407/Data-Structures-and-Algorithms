// Initialization of array 

#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i:arr) cout<<i<<" ";
    cout<<"\nSize of array: "<<sizeof(arr);
}

