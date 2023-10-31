#include <functional>
#include <iostream>
#include <vector>

#include "hm_5_screen.h"

using namespace std;

int main(int argc, const char **argv) {
  int arr[3][2] = {1, 2, 3, 4};
  for (auto a : arr) {
    cout << a[0] << " " << a[1] << endl;
  }

  int var[] = {1, 2, 3, 4};
  int *ptr = &var[2];
  cout << *ptr + 3 << *(ptr + 3) << endl;

  int par = 1;
  ++par;
  ostream << par << endl;
}