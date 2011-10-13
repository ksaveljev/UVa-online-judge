#include <iostream>
#include <string>
using namespace std;

int main(void)
{
  string input;

  while (getline(cin, input)) {
    if (input == "*") {
      break;
    }

    int a = 0, b = 64;
    int counter = 0;

    for (int i = 1, sz = input.size(); i < sz; i++) {
      switch (input[i]) {
        case 'W':
          a += 64;
          break;
        case 'H':
          a += 32;
          break;
        case 'Q':
          a += 16;
          break;
        case 'E':
          a += 8;
          break;
        case 'S':
          a += 4;
          break;
        case 'T':
          a += 2;
          break;
        case 'X':
          a += 1;
          break;
        case '/':
          if (a > 0) { // avoid a=0 case
            if (a == b) {
              counter++;
            }
          }
          a = 0;
          break;
      }
    }

    cout << counter << endl;
  }
  
  return 0;
}
