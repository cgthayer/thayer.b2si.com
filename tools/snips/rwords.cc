#include <iostream>
#include <string>
using namespace std;

char* Rev(char* s)
{
  
}

int main()
{
  while (true) {
    char str[1024];
    cin >> str;
    if (cin.eof() || !*str) break;
    cout << '[' << str << ']' << endl;
    Rev(str);
  }
  return 0;
}
