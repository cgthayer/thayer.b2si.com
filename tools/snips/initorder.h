#include <iostream>

// Note the difference when compiling
// g++ initorder2.cc initorder.cc
// g++ initorder.cc initorder2.cc

class Trace { 
public:
  Trace(const char *name) { 
    mName = name;
    cout << "Trace(" << mName << ")" << endl; 
  }

  ~Trace() { 
    cout << "~Trace(" << mName << ")" << endl;
  }

  const char* mName;
};

extern void i2function();

