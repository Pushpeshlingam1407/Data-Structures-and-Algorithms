// TODO: Recursion - when a function calls itself
//! Recursion is a method of solving problems where the solution depends on
//! solutions to smaller instances of the same problem.

//! Types of Recursion:
//! 1. Direct Recursion: when a function calls itself directly
//! 2. Indirect Recursion: when a function calls another function which calls
//! the first function

// TODO: Write a function that print numbers from 1 to n using recursion

#include <iostream>
using namespace std;

int printNumbers(int n) {
  if (n == 0)
    return 0;
  return printNumbers(n - 1);
  cout << n << " ";
}

//* If you want to print n to 1 using recursion: Just write the print statement before the recursive call
int printNumbers_reverse(int n) {
  if (n == 0)
    return 0;
  cout << n << " ";
  return printNumbers_reverse(n - 1);
}

int main() {
  int n;
  cout << "Enter a number: ";
  cin >> n;
  printNumbers(n);
  printNumbers_reverse(n);
}