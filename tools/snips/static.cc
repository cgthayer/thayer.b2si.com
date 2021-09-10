#include <iostream.h>

class Base {
 public:
  static const int i;
  static int si() { return i; }	        // In class scope i is Base::i
  static int si2() { return i; }
  int ii() const { return i; }
  int ii2() const { return i; }
  virtual int vi() const { return i; }
  virtual int vi2() const { return i; }
  virtual int vv() const { return 10; }
  virtual int vv2() const { return 10; }
};

const int Base::i = 100;

class Derived : public Base {
 public:
  static const int i;                // In class scope i is Derived::i
  // no si()
  static int si2() { return i; }
  // no ii()
  int ii2() const { return i; }
  // no vi()
  int vi2() const { return i; }	     // virtual
  // no vv()
  int vv2() const { return 20; }     // virtual
};

const int Derived::i = 200;

int main()
{
  Base b;
  Derived d;
  cout << b.si()  << " " << d.si()  << endl;                   // "100 100"
  cout << b.si2() << " " << d.si2() << endl;                   // "100 200"
  cout << b.vi2() << " " << d.vi2() << endl;                   // "100 200"
  cout << b.ii()  << " " << d.ii()  << endl;                   // "100 100"
  cout << b.ii2() << " " << d.ii2() << endl;                   // "100 200"
  cout << b.vv()  << " " << d.vv()  << endl;                   // "10 10"
  cout << b.vv2() << " " << d.vv2() << endl;                   // "10 20"
  cout << ((Base)d).vv() << " " << ((Base*)&d)->vv() << endl;  // "10 10"
  cout << ((Base)d).vv2() << " " << ((Base*)&d)->vv2() << endl;  // "10 20"

  Base *bp = &d;
  cout << bp->si() << " " << bp->si2() << endl;                // "100 100"
  cout << bp->ii() << " " << bp->ii2() << endl;                // "100 100"
  cout << bp->vi() << " " << bp->vi2() << endl;                // "100 200"
  cout << bp->vv() << " " << bp->vv2() << endl;                // "10 20"

  return 0;
}
