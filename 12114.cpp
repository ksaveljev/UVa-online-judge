#include <iostream>
using namespace std;

int main(void)
{
  int counter = 0;
  long long b, s;

  while (cin >> b >> s) {
    if (b == 0 && s == 0) {
      break;
    }

    counter++;

    cout << "Case " << counter << ": ";

    if (b == 1) {
      cout << ":-\\" << endl;
      continue;
    }

    if (b == s) {
      cout << ":-|" << endl;
      continue;
    }

    if (s > b) {
      cout << ":-|" << endl;
      continue;
    }

    if (s * (b-1) > b * (s-1)) {
      cout << ":-(" << endl;
    } else {
      cout << ":-)" << endl;
    }
  }
  
  return 0;
}
