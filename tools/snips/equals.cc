#include <iostream>

class A {
  public:
  int i;
};

class B {
  public:
  B() { cout << "B()" << endl; }
  B(const B& b) : i(b.i) { cout << "B(b)" << endl; }
  B& operator=(const B& b) { cout << "B.op=" << endl; }
  int i;
};

class C {
  public:
  C() { cout << "C()" << endl; }
  C(const C& c) : b(c.b) { cout << "C(c)" << endl; }
  C& operator=(const C& c) { cout << "C.op=" << endl; }
  B b;
};

class D {
  public:
  B b;
};

int main() {
  A a;
  A a2 = a;
  A a3;
  a3 = a2;

  cout << ": first b()" << endl << "..";
  B b;
  cout << ": b2 = b" << endl << "..";
  B b2 = b;
  cout << ": b3" << endl << "..";
  B b3;
  cout << ": b3 = b2" << endl << "..";
  b3 = b2;

  cout << ": first c()" << endl << "..";
  C c;
  cout << ": c2 = c" << endl << "..";
  C c2 = c;
  cout << ": c3" << endl << "..";
  C c3;
  cout << ": c3 = c2" << endl << "..";
  c3 = c2;

  cout << ": first d()" << endl << "..";
  D d;
  cout << ": d2 = d" << endl << "..";
  D d2 = d;
  cout << ": d3" << endl << "..";
  D d3;
  cout << ": d3 = d2" << endl << "..";
  d3 = d2;
}


