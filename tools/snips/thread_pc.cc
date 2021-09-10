#include <iostream>

using namespace std;

const int testSize = 10;

struct BufferT { 
  int mArray[testSize];
  void Set(int i, int v) { 
    pthread_mutex_lock(&mLock);
    mArray[i] = v;
    pthread_mutex_unlock(&mLock);
  }
  int Get(int i) { 
    int result;
    pthread_mutex_lock(&mLock);
    result = mArray[i];
    pthread_mutex_unlock(&mLock);
    return result;
  }

private:
  pthread_mutex_t mLock;
};

class Producer {
public:
  Producer(BufferT& buf) : mBuf(buf) {};
  int Start() {
    int r=time(0);
    int i=0;
    for (; i < testSize; i++) {
      r = int(r * 1.618) % 255;
      mBuf.Set(i, r);
      cout << "pro: i=" << i << " value=" << mBuf.mArray[i] << endl;
      cout << flush;
      sleep(1);
    }
    return 0;
  }

private:
  BufferT& mBuf;
};

class Consumer {
public:
  Consumer(BufferT& buf) : mBuf(buf) {};
  int Start() {
    int i=0;
    for (; i < testSize; i++) {
      cout << "con: i=" << i << " value=" << mBuf.mArray[i] << endl;
      cout << flush;
      sleep(1);
    }
    return 0;
  }
private:
  BufferT& mBuf;
};

BufferT b;
Producer pro(b);
Consumer con(b);

void* pstart(void* d) { pro.Start(); return 0; }
void* cstart(void* d) { con.Start(); return 0; }

int main()
{
  pthread_t t1, t2; 

  pthread_create(&t1, 0, &pstart, 0);
  pthread_create(&t2, 0, &cstart, 0);
  pthread_join(t1, 0);
  pthread_join(t2, 0);
  return 0;

}
