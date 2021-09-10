#include <iostream>
#include <map>
#include <assert.h>

using namespace std;

char firstNonRep(char* s)
{
  char* p = s;
  map<char, int> m;
  for (p=s; p && *p; p++) {
    m[*p]++;
  }
  for (p=s; p && *p; p++) {
    if (m[*p] == 1) 
      return *p;
  }
  return '\0';  
}

int main(int ac, char** av) {
  assert(ac > 1);
  char c = firstNonRep(av[1]);
  cout << "First non-repeating char in " << av[1] << " = " << c << endl;
}
