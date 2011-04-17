#include <iostream>
#include <string>
using namespace std;

bool is_palindrome(const string &s) {
  string r(s.rbegin(), s.rend());

  return s == r;
}

int main(void) {
  string input;
  string pal;

  while (getline(cin, input)) {
    if (input == "DONE")
      break;

    pal = "";
    for (int i = 0, sz = input.size(); i < sz; i++) {
      if (input[i] >= 'A' && input[i] <= 'Z' || input[i] >= 'a' && input[i] <= 'z')
        pal.push_back(toupper(input[i]));
    }

    if (is_palindrome(pal))
      cout << "You won't be eaten!" << endl;
    else
      cout << "Uh oh.." << endl;
  }

  return 0;
}
