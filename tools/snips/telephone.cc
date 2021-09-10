#include <iostream>
#include <string>
#include <assert.h>

using namespace std;

const char* lut(char c)
{
  switch (c) {
  case '2': return "abc";
  case '3': return "def";
  case '4': return "ghi";
  case '5': return "jkl";
  case '6': return "mno";
  case '7': return "pqrs";
  case '8': return "tuv";
  case '9': return "wxyz";
  default: return 0;
  }
}

void telephone(const string& head, const string& tail)
{
  if (tail.empty()) {
    cout << head << endl;
    return;
  }
  const char* opts = lut(tail[0]);
  string newtail(&tail[1]);
  if (!opts) {
    string newhead(head);
    newhead.append(1, tail[0]);
    telephone(newhead, newtail);
  } else {
    while (*opts) {
      string newhead(head);
      newhead.append(1, *opts);
      telephone(newhead, newtail);
      opts++;
    }
  }
}

int main(int ac, char** av)
{
  assert(ac>1);
  telephone("", av[1]);
}
