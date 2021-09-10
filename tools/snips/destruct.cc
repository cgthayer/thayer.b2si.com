#include <iostream>

using namespace std;

class B {
public:
  ~B() { cout << "\t~B " << (void*)this << endl; }
};

class D : public B {
public:
  ~D() { cout << "\t~D " << (void*)this << endl; }
};

class D2 : public B {
};

class Bv {
public:
  virtual ~Bv() { cout << "\t~Bv " << (void*)this << endl; }
};

class Bv2 : public Bv {
};

class Dv : public Bv {
public:
  virtual ~Dv() { cout << "\t~Dv " << (void*)this << endl; }
};


int main() {
  {
    cout << "D case::" << endl;
    D d;
  }
  {
    cout << "D2 case, default DTOR::" << endl;
    D2 d2;
  }
  {
    cout << "D with virtual case::" << endl;
    Dv dv;
  }
  {
    cout << "B2 case, default DTOR::" << endl;
    Bv2 bv2;
  }
  {
    cout << "Dv via b-ptr case::" << endl;
    Bv *bv = new Dv();
    delete bv;  // virtual magic
  }
  return 0;
}

// D case::
//         ~D 0xbf884c5c
//         ~B 0xbf884c5c
// D2 case, default DTOR::
//         ~B 0xbf884c5c
// 	    D with virtual case::
//         ~Dv 0xbf884c5c
//         ~Bv 0xbf884c5c
// 	    B2 case, default DTOR::
//         ~Bv 0xbf884c5c
// 	    Dv via b-ptr case::
//         ~Dv 0x92b7008
//         ~Bv 0x92b7008
