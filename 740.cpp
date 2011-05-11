#include <iostream>
#include <string>
using namespace std;

int bin2int(const string &s, string::iterator start, string::iterator end) {
  int tmp = 0;
  int counter = 4;
  for (; start != end; start++) {
    if (*start == '1') {
      tmp += (1<<counter);
    }
    counter--;
  }
  return tmp;
}

int main(void) {
  int n;
  string input;
  string downshift;
  string upshift;
  bool down;

  getline(cin, downshift);
  getline(cin, upshift);

  while (getline(cin, input)) {
    down = true;

    for (int i = 0, sz = input.size(); i < sz; i += 5) {
      n = bin2int(input, input.begin() + i, input.begin() + i + 5);

      if (n == 31) {
        down = false;
      } else if (n == 27) {
        down = true;
      } else {
        if (down) {
          cout << downshift[n];
        } else {
          cout << upshift[n];
        }
      }
    }
    cout << endl;
  }

  return 0;
}
