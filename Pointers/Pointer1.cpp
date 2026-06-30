//TODO: Pointer basics — a variable storing the memory address of another variable

#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b,*p,*q;
    cin>>a>>b;
    p=&a;
    q=&b;
    cout<<"Value of a: "<<*p<<"\n";
    cout<<"Value of b: "<<*q<<"\n";
    cout<<"Address of a: "<<p<<"\n";
    cout<<"Address of b: "<<q<<"\n";
}