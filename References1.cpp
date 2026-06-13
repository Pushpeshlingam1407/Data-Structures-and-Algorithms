//* Demonstrates structure usage with reference aliasing and string copy operations in C-style character arrays

#include <bits/stdc++.h>
using namespace std;

struct student{
    int code;
    char name[10];
    char city[10];
};

int main(){
    struct student st1;
    struct student &s = st1;

    cout << "size of st1: "<< sizeof(st1) << endl;
    cout << "size of s: " << sizeof(s) << endl;

    st1.code = 100;
    strcpy(st1.name, "Pushpesh");
    strcpy(st1.city, "Ongole");

    cout << st1.code << endl << st1.name << endl << st1.city << endl;
    cout << s.code << endl << s.name << endl << s.city << endl;

    s.code = 200;
    strcpy(s.name, "David");
    strcpy(s.city, "Hyd");

    cout << st1.code << endl << st1.name << endl << st1.city << endl;
    cout << s.code << endl << s.name << endl << s.city << endl;

    return 0;
}