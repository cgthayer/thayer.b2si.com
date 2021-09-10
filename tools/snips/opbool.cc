#include <iostream>

struct C {
  C(bool b): mB(b) {}
  operator bool() { cout << "[op bool]"; return mB; }
  bool mB;
};

int main() {
  C c(true), d(false);
  cout << c << ", " << d << ", " << (!c) << ", " << (!d) << endl;
}
