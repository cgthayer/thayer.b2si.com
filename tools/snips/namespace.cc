#include <iostream>

namespace Bar {
  typedef const char* CspT;
  const char* version = "bar 1.1";
}

class Foo {
public:
  void Method() {
    using namespace Bar;
    cout << version << endl;
    CspT mv = "Local 1.2";
    cout << mv << endl;
    CspT version = "Obj 1.3";
    cout << version << endl;
    cout << Bar::version << endl;
  }
};

int main()
{
  Foo f;
  f.Method();
  return 0;
}
