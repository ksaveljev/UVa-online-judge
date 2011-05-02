#include <iostream>
#include <string>
#include <map>
using namespace std;

bool is_vowel(char c) {
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

bool special_case(const string &s) {
  if (s[s.size()-1] == 'o' || s[s.size()-1] == 's' || s[s.size()-1] == 'x')
    return true;

  if (s.size() < 2)
    return false;

  if (s[s.size()-2] == 'c' && s[s.size()-1] == 'h' || s[s.size()-2] == 's' && s[s.size()-1] == 'h')
    return true;

  return false;
}

int main(void) {
  int L, N;
  string w1, w2;
  map<string,string> irregular;

  cin >> L >> N;

  while (L--) {
    cin >> w1 >> w2;
    irregular[w1] = w2;
  }

  while (N--) {
    cin >> w1;

    if (irregular.find(w1) != irregular.end()) {
      cout << irregular[w1] << endl;
      continue;
    }

    if (w1[w1.size()-1] == 'y' && w1.size() > 1 && !is_vowel(w1[w1.size()-2])) {
      w1[w1.size()-1] = 'i';
      cout << w1 << "es" << endl;
    } else if (special_case(w1)) {
      cout << w1 << "es" << endl;
    } else {
      cout << w1 << "s" << endl;
    }
  }

  return 0;
}
