#include <list>
#include <string>

class IfThenElseFunctor {
public:
  template <typename T>
  T operator()(bool test, const T &thenVal, const T &elseVal) {
    if (test) {
      return thenVal;
    } else {
      return elseVal;
    }
  }
};

int main(int argc, const char **argv) {
  std::list<std::string> args;
  args.push_back(argv[0]);

  return 0;
}