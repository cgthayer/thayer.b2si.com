#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

using namespace std;

void *t(void * arg)
{
  if (!arg) return 0;
  char a = *(char *)arg;
  int c = 0;
  for (; c < 6; c++) {
    cout << a << flush;
    sleep(1);
  }
  return 0;
}

int main() 
{
  pthread_t t1, t2, t3;
  char c1 = '|', c2 = '/', c3 = '-';
  if (pthread_create(&t1, 0, &t, &c1) != 0) {
    cerr << "thread create: " << strerror(errno) << endl;
  }
  sleep(2);
  if (pthread_create(&t2, 0, &t, &c2) != 0) {
    cerr << "thread create: " << strerror(errno) << endl;
  }
  sleep(1);
  if (pthread_create(&t3, 0, &t, &c3) != 0) {
    cerr << "thread create: " << strerror(errno) << endl;
  }
  pthread_join(t1, 0);
  pthread_join(t2, 0);
  pthread_join(t3, 0);
  cout << endl;
  // Typical result: "||/|/-|/-|/-|/-/--"
  return 0;
}

