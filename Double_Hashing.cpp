// TODO: Demonstrates Double Hashing for collision resolution in Hash Tables.
//? What is Double Hashing?
//? When a collision occurs, we use a second hash function to determine the
//? step size for probing.

//* Formula
//? h1(key) = key % SIZE
//? h2(key) = 7 - (key % 7)
//? probe(i) = (h1(key) + i * h2(key)) % SIZE

// ! Time Complexity:
// ! Insert: O(1) average, O(n) worst case (heavy clustering)
// ! Search: O(1) average, O(n) worst case
// ! Delete: O(1) average, O(n) worst case
// ! Space Complexity: O(n) — fixed-size array

#include <iostream>
using namespace std;

#define SIZE 10
