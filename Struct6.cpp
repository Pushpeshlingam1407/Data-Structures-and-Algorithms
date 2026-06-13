//* Demonstrates use of a struct with pointer-based functions to initialize, modify, and compute the area of a rectangle.

#include <bits/stdc++.h>
using namespace std;

struct Rectangle {
    int length;
    int breadth;
};

void init(Rectangle *r, int l, int b) {
    r->length = l;
    r->breadth = b;
}

int area(Rectangle *r) {
    return (r->length * r->breadth);
}

void updateLength(Rectangle *r, int l) {
    r->length = l;
}

void updateBreadth(Rectangle *r, int b) {
    r->breadth = b;
}

int main() {
    Rectangle r;
    init(&r, 10, 20);

    cout << "Area: " << area(&r) << endl;

    updateLength(&r, 15);
    cout << "Area after updating length: " << area(&r) << endl;

    updateBreadth(&r, 25);
    cout << "Area after updating breadth: " << area(&r) << endl;

    return 0;
}