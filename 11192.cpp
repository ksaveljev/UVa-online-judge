#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(void) {
  int g;
  int gsize;
  string input;

  while (cin >> g) {
    if (g == 0)
      break;

    cin >> input;

    gsize = input.size() / g;

    for (int i = 0; i * gsize < input.size(); i++) {
      reverse(input.begin() + i * gsize, input.begin() + i * gsize + gsize);
    }

    cout << input << endl;
  }

  return 0;
}
