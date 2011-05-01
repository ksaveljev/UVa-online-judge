#include <iostream>
#include <string>
using namespace std;

int main(void) {
  string input;
  string powerstring;

  while (getline(cin, input)) {
    if (input == ".")
      break;

    for (int i = 1, sz = input.size(); i <= sz; i++) {
      if (sz % i != 0)
        continue;

      string tmp(input.begin(), input.begin() + i);
      powerstring = "";

      for (int j = 0; j < sz / i; j++)
        powerstring += tmp;

      if (powerstring == input) {
        cout << sz / i << endl;
        break;
      }
    }
  }

  return 0;
}
