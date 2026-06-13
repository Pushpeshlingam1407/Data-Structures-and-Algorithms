// Program demonstrating a Rectangle class using scope resolution operator (::) for member function definitions

#include <bits/stdc++.h>
using namespace std;

class Rectangle{
private:
    int length;
    int breadth;
public:
    void init(int l, int b);
    int area();
    void updateLength(int l);
    void updateBreadth(int b);
};

void Rectangle::init(int l, int b) {
    length = l;
    breadth = b;
}

int Rectangle::area() {
    return (length * breadth);
}

void Rectangle::updateLength(int l) {  
    length = l;
}

void Rectangle::updateBreadth(int b) { 
    breadth = b;
}

int main() {
    Rectangle r;
    r.init(10, 20);

    cout << "Area: " << r.area() << endl;

    r.updateLength(15);
    cout << "Area after updating length: " << r.area() << endl;

    r.updateBreadth(25);
    cout << "Area after updating breadth: " << r.area() << endl;

    return 0;
}