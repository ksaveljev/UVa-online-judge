#include <iostream>
#include <string>
using namespace std;

bool is_vowel(char c) {
  char vowels[6] = {'a', 'e', 'i', 'o', 'u', 'y'};

  for (int i = 0; i < 6; i++)
    if (vowels[i] == c)
      return true;

  return false;
}

int main(void) {
  string input;
  int current;
  int count;
  char prev;

  while (getline(cin, input)) {
    if (input == "e/o/i")
      break;

    bool ok = true;
    current = 1;
    count = 0;
    prev = ' ';

    for (int i = 0, sz = input.size(); i < sz; i++) {
      if (input[i] == '/') {
        if (current == 1) {
          if (count != 5) {
            ok = false;
            cout << 1 << endl;
            break;
          }
        } else { // current == 2
          if (count != 7) {
            ok = false;
            cout << 2 << endl;
            break;
          }
        }
        count = 0;
        current++;
      } else if (is_vowel(input[i])) {
        if (!is_vowel(prev))
          count++;
      }

      prev = input[i];
    }

    if (ok && count != 5) {
      ok = false;
      cout << 3 << endl;
    }

    if (ok) {
      cout << "Y" << endl;
    }
  }

  return 0;
}
