#include <iostream>

class A {
 public:
  int a;
  A() : a(1) {}
};

class B: public A {
 public:
  int b;
  B(): b(2) {};
};

class C: public A {
 public:
  int c;
  C(): c(3) {};
  C& operator=(const C& rhs) {
    if (&rhs == this) return *this;
    c = rhs.c;
    return *this;
  };
};

ostream& operator<<(ostream& lhs, const B& b) {
  lhs << "[a=" << b.a << ", b=" << b.b << "]";
  return lhs;
}

ostream& operator<<(ostream& lhs, const C& c) {
  lhs << "[a=" << c.a << ", c=" << c.c << "]";
  return lhs;
}


int main() {
  B b0;
  b0.a = 10;

  B b1;
  b1.b = 20;
  cout << "b1=" << b1 << " "
    << "b1endl;

  b1 = b0;
  cout << b0

  return 0;
}

