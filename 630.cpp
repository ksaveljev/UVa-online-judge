#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <cstdio>
using namespace std;

int main(void) {
  int cases;
  int words;
  int count;
  string input;
  multimap<string,string> m;
  multimap<string,string>::iterator it;
  pair<multimap<string,string>::iterator,multimap<string,string>::iterator> ret;

  cin >> cases;

  while (cases--) {
    m.clear();

    cin >> words;
    cin.ignore(100, '\n');

    for (int i = 0; i < words; i++) {
      getline(cin, input);
      string tmp(input);
      sort(tmp.begin(), tmp.end());
      m.insert(make_pair(tmp, input));
    }

    while (getline(cin, input)) {
      if (input == "END")
        break;

      string tmp(input);
      sort(tmp.begin(), tmp.end());

      cout << "Anagrams for: " << input << endl;

      if (m.count(tmp) == 0) {
        cout << "No anagrams for: " << input << endl;
      } else {
        count = 0;
        ret = m.equal_range(tmp);
        for (it = ret.first; it != ret.second; it++) {
          count++;
          printf("%3d) ", count);
          cout << (*it).second << endl;
        }
      }
    }

    if (cases)
      cout << endl;
  }

  return 0;
}
