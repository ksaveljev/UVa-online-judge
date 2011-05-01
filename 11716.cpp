#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(void) {
  int cases;
  int sq;
  string input;

  cin >> cases;
  cin.ignore(100, '\n');

  while (cases--) {
    getline(cin, input);

    sq = sqrt(input.size());

    if (sq * sq != input.size()) {
      cout << "INVALID" << endl;
      continue;
    }

    for (int i = 0; i < sq; i++) {
      for (int j = 0; i + j * sq < input.size(); j++) {
        cout << input[i + j * sq];
      }
    }
    cout << endl;
  }

  return 0;
}
