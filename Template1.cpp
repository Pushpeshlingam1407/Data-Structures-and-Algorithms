// Program demonstrating class template for basic arithmetic operations (add and subtract)

#include <bits/stdc++.h>
using namespace std;

template<class T>
class Arithmetic{
private:
    T a;
    T b;
public:
    Arithmetic(T a, T b);
    T add();
    T sub();
};

template <class T> // Must declare template<class T> for each member function definition outside the class scope
Arithmetic<T>::Arithmetic(T a,T b){
    this->a=a;
    this->b=b;
}

template<class T>
T Arithmetic<T>::add(){
    return a+b;
}

template<class T>
T Arithmetic<T>::sub(){
    return a-b;
}

int main() {
    Arithmetic<int> ar1(10,5);
    cout<<"Addition of int values: "<<ar1.add()<<endl;
    cout<<"Subtraction of int values: "<<ar1.sub()<<endl;

    Arithmetic<float> ar2(13.5,13.8);
    cout<<"Addition of float values: "<<ar2.add()<<endl;
    cout<<"Subtraction of float values: "<<ar2.sub()<<endl;
}