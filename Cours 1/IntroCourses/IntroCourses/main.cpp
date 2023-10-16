#include <functional>
#include <iostream>
#include <vector>
using namespace std;

typedef int (*FuncPtr)(int, int);

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

void put_in_vector() {
  vector<FuncPtr> v = {add, subtract, multiply, divide};
  for (size_t i = 0; i < 4; i++) {
    cout << v[i] << " ";
  }
}

int main(int argc, const char **argv) {
  put_in_vector();
  // Sorry, I probably misunderstood the question 6.

  return 0;
}