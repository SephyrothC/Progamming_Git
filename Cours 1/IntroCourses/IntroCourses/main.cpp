#include <iostream>
#include <random>
#include <vector>
using namespace std;

// A function that takes two int pointers as parameters and swaps their values
void swap_number_pointer(int *a, int *b) {
  // Declare and initialize a temporary int variable
  int tmp = 0;
  // Store the value of a in tmp
  tmp = *a;
  // Assign the value of b to a
  *a = *b;
  // Assign the value of tmp to b
  *b = tmp;
}

// A function that takes two int references as parameters and swaps their values
void swap_number_reference(int &a, int &b) {
  // Store the value of a in a temporary variable
  int temp = a;
  // Assign the value of b to a
  a = b;
  // Assign the value of temp to b
  b = temp;
}

// A function that takes two int parameters and returns their greatest common
// divisor (GCD)
int gcd_loop(int a, int b) {
  int res = 0, tmp = 0;
  while (b != 0) {
    tmp = b;
    b = a % b;
    a = tmp;
    res = a;
    
  }
  return res;
}

// A function that takes two int parameters and returns their greatest common
// divisor (GCD)
int gcd_rec(int a, int b) {
  // If b is zero, then a is the GCD
  if (b == 0)
    return a;
  // Otherwise, recursively call the function with b and the remainder of a
  // divided by b
  return gcd_rec(b, a % b);
}

// This is a test program to demonstrate the functions
int main() {
  // Declare and initialize two int variables
  int x = 10;
  int y = 20;
  // Print their values before swapping
  cout << "Before swapping: x = " << x << ", y = " << y << endl;
  // Call the swap function with the addresses of x and y
  swap_number_pointer(&x, &y);
  // Print their values after swapping
  cout << "After swapping with pointer: x = " << x << ", y = " << y << endl;
  // Reinitialize two int variables
  x = 10;
  y = 20;
  // Call the swap function with the addresses of x and y
  swap_number_reference(x, y);
  // Print their values after swapping
  cout << "After swapping with reference: x = " << x << ", y = " << y << endl;

  // Answer to the question 7 :
  //   I perfer to use pointer insted of reference but :
  //
  //   - Pointers can be NULL, reassigned, and offer multiple indirection.
  //     References cannot.
  //
  //   - References are safer, easier, and can overload operators. Pointers
  //     cannot.
  //
  //   So normally Reference is better

  // Declare and initialize two int variables
  int a = 48;
  int b = 18;
  // Print their values before swapping
  cout << endl
       << "gcd_rec(" << a << "," << b << ") = " << gcd_rec(a, b) << endl;
  // Call the swap function with the addresses of x and y
  // Declare and initialize two int variables
  a = 48;
  b = 18;
  // Print their values before swapping
  cout << endl
       << "gcd_loop(" << a << "," << b << ") = " << gcd_loop(a, b) << endl;
  // Call the swap function with the addresses of x and y

  return 0;
}
