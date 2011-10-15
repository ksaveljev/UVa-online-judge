#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

int main(void)
{
  string input;

  while (getline(cin, input)) {
    if (input == "*") {
      break;
    }

    transform(input.begin(), input.end(), input.begin(), ::tolower);

    stringstream ss(input, stringstream::in);

    char ch = ' ';
    bool ok = true;
    while (ss >> input) {
      if (ch == ' ') {
        ch = input[0];
      } else {
        if (ch != input[0]) {
          ok = false;
        }
      }
    }

    if (ok) {
      cout << "Y" << endl;
    } else {
      cout << "N" << endl;
    }
  }
  
  return 0;
}
