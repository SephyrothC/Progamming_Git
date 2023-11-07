#include <iostream>
#include <list>
#include <shared_mutex>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

bool compVector(vector<int> &vectorA, vector<int> &vectorB) {
  if (vectorA == vectorB)
    return true;
  return false;
}

bool compListVect(vector<int> &vectorA, list<int> &listB) {
  if (vectorA.size() != listB.size())
    return false;
  auto iterator = listB.begin();
  for (int i = 0; i < vectorA.size(); i++) {
    if (vectorA[i] != *iterator)
      return false;
    ++iterator;
  }
  return true;
}

string NameCreator(string name, string prefix, string suffix) {
  string CompleteName;
  CompleteName.append(prefix);
  CompleteName.append(name);
  CompleteName.append(suffix);

  return CompleteName;
}

string NameCreator2(string name, string prefix, string suffix) {
  string CompleteName;
  int size = 0;
  CompleteName.insert(0, prefix);
  CompleteName.insert(prefix.size(), name);
  CompleteName.insert(prefix.size() + name.size(), suffix);
  return CompleteName;
}

int main(int argc, const char **argv) {
  vector<int> a = {1, 2, 3, 4};
  vector<int> b = {1, 2, 3, 5};
  list<int> c = {1, 2, 3, 4};
  list<int> d = {1, 2, 3, 5};

  printf("same : %d\n", compVector(a, a));
  printf("diff :%d\n", compVector(a, b));
  printf("same : %d\n", compListVect(a, c));
  printf("diff :%d\n", compListVect(a, d));
  printf("\n");

  string name, prefix, suffix;

  cout << "Enter name : " << endl;
  cin >> name;
  cout << "Enter prefix : " << endl;
  cin >> prefix;
  cout << "Enter suffix : " << endl;
  cin >> suffix;

  cout << "append :" << NameCreator(name, prefix, suffix) << endl;
  cout << "insert :" << NameCreator2(name, prefix, suffix) << endl;

  return 0;
}