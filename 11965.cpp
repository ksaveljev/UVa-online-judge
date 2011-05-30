#include <iostream>
#include <string>
using namespace std;

int main(void) {
  int t, n;
  string input;
  char prev = 'c';

  cin >> t;

  for (int c = 0; c < t; c++) {
    cin >> n;
    cin.ignore(100, '\n');

    if (c)
      cout << endl;

    cout << "Case " << c+1 << ":" << endl;
    for (int i = 0; i < n; i++) {
      getline(cin, input);
      prev = 'c';
      for (int j = 0, sz = input.size(); j < sz; j++) {
        if (input[j] == ' ') {
          if (prev != ' ') {
            cout << input[j];
          }
          prev = ' ';
        } else {
          prev = 'c';
          cout << input[j];
        }
      }
      cout << endl;
    }
  }

  return 0;
}
