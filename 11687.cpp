#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int length(int n) {
  return (int)log10(n) + 1;
}

int main(void) {
  int n;
  string input;

  while (getline(cin, input)) {
    if (input == "END")
      break;

    if (input == "1") {
      cout << 1 << endl;
      continue;
    }

    int result = 1;
    n = input.size();

    while (n != 1) {
      n = length(n);
      result++;
    }

    cout << result+1 << endl;
  }

  return 0;
}
