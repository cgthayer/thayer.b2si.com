#include <iostream>

class C {
 public:
  C(): mi(42) {}
  operator const char*() const { return "Hello World"; }
  operator const int&() const { return mi; } // const int, preserve encap.
 private:
  int mi;
};

int main() {
  C c;
  cout << (const char*)c << endl;
  cout << (const int)c << endl;
  cout << (int)c << endl;	// works because ostream takes const int
  return 0;
}
