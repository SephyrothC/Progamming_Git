#include <functional>
#include <iostream>
#include <vector>

#include "hm_5_screen.h"

using namespace std;

using FuncPtr = int (*)(int, int);

// Function to add two integers
int add(int a, int b) { return a + b; }

// Function to subtract two integers
int subtract(int a, int b) { return a - b; }

// Function to multiply two integers
int multiply(int a, int b) { return a * b; }

// Function to divide two integers
int divide(int a, int b) {
  if (b != 0)
    return round(a / b);
  else
    return 0; // Return 0 if denominator is 0
}

int put_in_vector() {
  vector<FuncPtr> v = {add, subtract, multiply, divide};
  for (size_t i = 0; i < 4; i++) {
    cout << v[i] << " ";
  }
  return 0;
}

int main(int argc, const char **argv) {
  // Q6
  put_in_vector();

  // Q17
  Screen myScreen(5, 5, 'X');
  myScreen.move(4, 0).set('#').display(cout);
  cout << "\n";
  myScreen.display(cout);
  cout << "\n";

  // 1. **Performance**: Returning a copy of an object, especially a large one,
  // can be less efficient because it involves copying all the data members of
  // the object.

  // 2. **Chaining**: One common reason to return a reference is to allow
  // function chaining. For example, with the current design you can write code
  // like this: `myScreen.move(4,0).set('#');` This code moves the cursor and
  // then sets the character at the new position. If `move` returned a copy of
  // `Screen`, this code wouldn't work as expected. It would move the cursor in
  // the copy of the screen, set the character in that copy, and then discard
  // the copy, leaving the original `Screen` object unchanged.

  // 3. **Consistency**: If some functions return a copy and others return a
  // reference, it can lead to confusion about which version of the object (the
  // original or the copy) is being modified in any given piece of code.

  // So, while it's technically possible to change these functions to return
  // `Screen` instead of `Screen&`, doing so could lead to unexpected behavior
  // and performance issues.

  return 0;
}