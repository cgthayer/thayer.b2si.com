#include "initorder.h"

void s0() {
  static Trace t("s0");
}

void s1() {
  static Trace t("s1");
}

Trace g0("g0");
Trace g1("g1");

int main() 
{
  Trace a0("a0");
  Trace a1("a1");
  s0();
  s1();
  i2function();
}
