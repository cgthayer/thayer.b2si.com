#include <assert.h>
#include <string.h>
#include <iostream>

using namespace std;

void permute(char* s)
{
  int len = strlen(s);
  char* out = new char[len+1];
  for (int c = (1<<len)-1; c > 0; c--) {
    int n = c;
    int i = 0, o = 0;
    while (n>0) {
      if (n&1) out[o++] = s[i];
      i++;
      n=n>>1;
    }
    out[o] = '\0';
    cout << "  " << out << endl;
  }
  delete out;
}

int main(int ac, char** av)
{
  assert(ac>1);
  for (int i=1; i<ac; i++) {
    cout << av[i] << ":" << endl;
    permute(av[i]);
  }
  return 0;
}
