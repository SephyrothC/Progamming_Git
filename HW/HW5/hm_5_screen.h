#pragma once
#include <iostream>
using namespace std;

class Screen {
public:

  using pos = string::size_type;

  // Default constructor
  Screen() = default;

  // Constructor that takes values for height and width
  Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht * wd, ' ') {}

  // Constructor that takes values for height, width, and a character
  Screen(pos ht, pos wd, char c)
      : height(ht), width(wd), contents(ht * wd, c) {}

  // get function
  char get() const { return contents[cursor]; }
  char get(pos ht, pos wd) const;

  // move function
  Screen &move(pos r, pos c);

  // set function
  Screen &set(char);
  Screen &set(pos, pos, char);

  // display function
  Screen &display(ostream &os) {
    do_display(os);
    return *this;
  };
  const Screen &display(ostream &os) const {
    do_display(os);
    return *this;
  }

private:
  pos cursor = 0;
  pos height = 0;
  pos width = 0;
  string contents;
  void do_display(ostream &os) const { os << contents; }
};

inline Screen &Screen::set(char c) {
  contents[cursor] = c;
  return *this;
}

inline Screen &Screen::set(pos r, pos col, char c) {
  contents[r * width + col] = c;
  return *this;
}

inline Screen &Screen::move(pos r, pos c) {
  pos row = r * width; // compute the row location
  cursor = row + c;    // move cursor to the column within that row return this;
  return *this;        // return this object as an Ivalue
}

inline char Screen::get(pos r, pos c) const { // declared as inline in the class
  pos row = r * width;                 // compute row location
  return contents[row + c];            // return character at the given column
}
