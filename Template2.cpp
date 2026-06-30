//TODO: Generic arithmetic class using C++ templates supporting both int and float types

#include <bits/stdc++.h>
using namespace std;

template <class T>
class Arithmetic{
    private:
        T a;
        T b;
    public:
        Arithmetic(T a,T b){
            this->a=a;
            this->b=b;
        }
        T add(){
            return a+b;
        }
        T sub(){
            return a-b;
        }
};
int main(){
    Arithmetic<int>ar1(15,20);
    cout<<"Addition of int values: "<<ar1.add()<<endl;
    cout<<"Subtraction of int values: "<<ar1.sub()<<endl;
    Arithmetic<float>ar2(13.5,13.8);
    cout<<"Addition of float values: "<<ar2.add()<<endl;
    cout<<"Subtraction of float values: "<<ar2.sub()<<endl;
}