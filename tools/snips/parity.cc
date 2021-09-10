#include <assert.h>
#include <stdlib.h>

int parity(int i);

int main(int ac, char** av)
{
  assert(ac > 1);
  int i = atoi(av[1]);
  return parity(i);
}

int parity(int i)
{
  int res=0;
  for (int j=0; j <= sizeof(int)<<3; j++) {
    if (i&1) res++;
    i = i>>1;
  } 
  return res;
}
