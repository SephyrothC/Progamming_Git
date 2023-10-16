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

int put_in_vector(int a, int b) {
  vector<FuncPtr> v = {add, subtract, multiply, divide};
  for (size_t i = 0; i < 4; i++) {
    cout << v[i] << " ";
  }
  return 0;
}

class Screen {
public:
  typedef std::string::size_type pos;
  Screen() = default;
  char get() const { return contents[cursor]; }
  inline char get(pos ht, pos wd) const;
  Screen &move(pos r, pos c);

private:
  pos cursor = 0;
  pos height = 0, width = 0;
  std::string contents;
};

// function to move the cursor within a row
Screen &Screen::move(pos r, pos c) {
  pos row = r * width; // compute row location
  cursor = row + c;    // move cursor to column within that row
  return *this;        // return this object as an lvalue
}

// function to get the character at a given location
char Screen::get(pos r, pos c) const {
  pos row = r * width;      // compute row location
  return contents[row + c]; // return character at the given column
}

int main(int argc, const char **argv) {
  put_in_vector(3, 5);
  return 0;
}