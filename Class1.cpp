//* Demonstrates the definition and usage of a C++ class with private attributes, initialization, modification, and area calculation methods.

#include <bits/stdc++.h>
using namespace std;

class Rectangle {
private:
    int length;
    int breadth;

public:
    void init(int l, int b) {
        length = l;
        breadth = b;
    }

    int area() {
        return (length * breadth);
    }

    void updateLength(int l) {
        length = l;
    }

    void updateBreadth(int b) {
        breadth = b;
    }
};

int main() {
    Rectangle r;
    r.init(10, 20);

    cout << "Area: " << r.area() << endl;

    r.updateLength(15);
    cout << "Area after updating length: " << r.area() << endl;

    r.updateBreadth(25);
    cout << "Area after updating breadth: " << r.area() << endl;
}