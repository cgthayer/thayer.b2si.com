#include <iostream.h>

class Foo {};
class Bar {};

class Thayer {
public:
  Thayer(const Bar& b) { cout << "CTOR Thayer from Bar" << endl; }
  Thayer() { cout << "CTOR Thayer" << endl; }
};

int main()
{
  Foo f;
  Bar b;
  static_cast<Thayer>(b);  // CTOR Thayer from Bar
  // static_cast<Bar>(f);  // no matching function for call to `Bar::Bar (Foo &\
)'

  return 0;
}
