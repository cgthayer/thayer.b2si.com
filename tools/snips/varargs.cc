#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

char * foo(int i, char *fmt, ...) {
  static char buffer[1024];
  va_list ap;
  va_start(ap, fmt);
  sprintf(buffer, "%d:", i);
  vsprintf(buffer + strlen(buffer), fmt, ap);
  va_end(ap);
  return buffer;
}

int main() {
  cout << foo(42, "%f", 3.145) << endl;
}
