#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <iostream.h>
#include <errno.h>

void *t(void * arg)
{
  int id = *(int*)arg;
  int c = 0;
  int MB = 1024*1024;  // megabyte
  while (true) {
    char *foo = new char[50 * MB];
    cout << id << ":" << c++ << " " << flush;
    sleep(1);
  }
}

int main() 
{
  int thread_count = 0;
  while (true) {
    pthread_t thr;
    if (pthread_create(&thr, 0, &t, &thread_count) != 0) {
      cerr << "thread create: " << strerror(errno) << endl;
    }
    thread_count++;
    cout << "[thread " << thread_count << "] " << flush;
    sleep(10);
  }
  //  pthread_join(thr, 0);
  cout << endl;
  return 0;
}

