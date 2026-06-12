//* Structures: Heterogeneous type of data elements grouped together under a single name.

//* Syntax:
/* struct structure_name{
     data_type member1;
     data_type member2;

 } variable_name;
*/

// Code for structure
#include <bits/stdc++.h>
using namespace std;
struct Student{
    int code;
    char name[100];
    char course[100];
};
int main(){
    struct Student s1={100,"Pushpesh","DSA"};
    cout<<s1.code<<" "<<s1.name<<" "<<s1.course;
}

