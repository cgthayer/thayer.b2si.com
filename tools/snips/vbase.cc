#include <iostream>

using namespace std;

class Base {
 public:
  virtual void foo() { cout << "Base::foo" << endl; }
  void bar() { cout << "Base::bar" << endl; }

  virtual void chain() { cout << "Base::chain" << endl; }
};

class D : public Base {
 public:
  void foo() { cout << "D::foo" << endl; }
  void bar() { cout << "D::bar" << endl; }
  virtual void chain() { Base::chain(); cout << "D::chain" << endl; }
};

int main() {
  Base b;
  D d;
  cout << "b::" << endl;
  b.foo();
  b.bar();
  b.chain();
  cout << endl;

  cout << "d::" << endl;
  d.foo();
  d.bar();
  d.chain();
  cout << endl;

  cout << "d as a b::" << endl;
  Base& b2(d);
  b2.foo();
  b2.bar();
  b2.chain();
  return 0;
}
