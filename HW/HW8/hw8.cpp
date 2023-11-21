#include <iostream>
#include <string>

class numbered_1 {
private:
  static int unique;
  int mysn;

public:
  numbered_1() { mysn = unique++; }
  int get_mysn() const { return mysn; }
};

int numbered_1::unique = 0;

void f_1(numbered_1 s) { std::cout << s.get_mysn() << std::endl; }

class numbered_2 {
private:
  static int unique;
  int mysn;

public:
  numbered_2() { mysn = unique++; }
  numbered_2(const numbered_2 &) { mysn = unique++; }
  int get_mysn() const { return mysn; }
};

int numbered_2::unique = 0;

void f_2(numbered_2 s) { std::cout << s.get_mysn() << std::endl; }

class numbered_3 {
private:
  static int unique;
  int mysn;

public:
  numbered_3() { mysn = unique++; }
  numbered_3(const numbered_3 &) { mysn = unique++; }
  int get_mysn() const { return mysn; }
};

int numbered_3::unique = 0;

void f_3(const numbered_3 &s) { std::cout << s.get_mysn() << std::endl; }

class Employee {
public:
  // Default constructor
  Employee() : name("Default"), id(++s_id) {}

  // Constructor that takes a string representing the employee's name
  Employee(const std::string &name) : name(name), id(++s_id) {}

  // Accessor methods for name and id
  std::string getName() const { return name; }
  int getId() const { return id; }

  // Delete copy constructor and copy-assignment operator
  Employee(const Employee &) = delete;
  Employee &operator=(const Employee &) = delete;

private:
  std::string name;
  int id;

  // Static data member
  static int s_id;
};

// Initialize static data member
int Employee::s_id = 0;

int main(int argc, const char **argv) {
  numbered_1 a, b = a, c = b;
  printf("1)\n");
  f_1(a), f_1(b), f_1(c);

  numbered_2 e, f = e, g = f;
  printf("2)\n");
  f_2(e), f_2(f), f_2(g);

  numbered_3 h, i = h, j = i;
  printf("3)\n");
  f_3(h), f_3(i), f_3(j);
}

// Q4

//  1)
//   numbered a;
//   This line creates a numbered object
//   a.The constructor of numbered assigns a unique serial number to
//   a.Let’s say this serial number is 0.

// numbered b = a;
// This line creates a numbered object b and initializes it with a.Because
// the copy constructor is used, b gets the same serial number as a.So, the
// serial number of b is also 0.

// numbered c = b;
// This line creates a numbered object c and initializes it with b.Again,
// because the copy constructor is used,
// c gets the same serial number as b.So,
// the serial number of c is also 0.

// 2)

// numbered a;
// This line creates a numbered object
// a.The constructor of numbered assigns a unique serial number to
// a.Let’s say this serial number is 3.

// numbered b = a;
// This line creates a numbered object b and initializes it with a.Because
// the copy constructor is used, b gets a new unique serial number.Let’s say
// this serial number is 4.

// numbered c = b;
// This line creates a numbered object c and initializes it with b.Again,
// because the copy constructor is used,
// c gets a new unique serial number.Let’s say this serial number is 5.

// 3)
//  Passing numbered object by reference to function f as const numbered
//  &doesn’t change the output.The function f prints the serial number of its
//  argument, which remains the same whether the argument is passed by value
//  or by reference.So, the output remains 0, 1, 2 assuming numbered has a
//  copy constructor that assigns a new unique serial number to each object.If
//  not, the output is 0 printed three times.return 0;

// Q5)

// The `Employee` class doesn't need custom copy-control members.
// The default copy constructor and copy-assignment operator provided by
// the compiler are sufficient as they correctly copy the `name` and `id`.
// The default destructor is also adequate as there are no resources to free
// when an `Employee` object is destroyed.
