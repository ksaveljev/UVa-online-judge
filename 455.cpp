#include <iostream>
#include <string>
using namespace std;

int main(void) {
  int n;
  bool found;
  string input;

  cin >> n;
  cin.ignore(100, '\n');

  while (n--) {
    cin.ignore(100, '\n');
    getline(cin, input);

    for (int i = 1, sz = input.size(); i <= sz; i++) {
      if (sz % i != 0)
        continue;

      string t = string(input.begin(), input.begin() + i);
      string tmp = "";

      for (int j = 0; j < sz / i; j++)
        tmp += t;

      if (tmp == input) {
        found = true;
        cout << i << endl;
        break;
      }
    }

    if (!found)
      cout << input.size() << endl;

    if (n)
      cout << endl;
  }

  return 0;
}
