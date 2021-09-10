#include<iostream>

using namespace std;

class A { int a; };
class B { int b; };
class C : public A, public B { /*empty*/ };

int main() {
  cout << "sizeof(A)\t" << sizeof(A) << endl;
  cout << "sizeof(B)\t" << sizeof(B) << endl;
  cout << "sizeof(C)\t" << sizeof(C) << endl;
  C c;
  cout << "&c\t" << &c << endl;
  cout << "(A*)&c\t" << (A*)&c << endl;
  cout << "(B*)&c\t" << (B*)&c << endl;

  return 0;
}

// sizeof(A)       4
// sizeof(B)       4
// sizeof(C)       8
// &c      0xbf9c1c1c
// (A*)&c  0xbf9c1c1c
// (B*)&c  0xbf9c1c20
