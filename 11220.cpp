#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(void) {
  int cases;
  string input;
  int counter;

  cin >> cases;
  cin.ignore(100, '\n');
  cin.ignore(100, '\n');

  for (int i = 0; i < cases; i++) {
    cout << "Case #" << i+1 << ":" << endl;

    while (getline(cin, input)) {
      if (input == "")
        break;

      stringstream ss;
      ss << input;

      counter = 1;

      while (ss >> input) {
        if (input.size() >= counter) {
          cout << input[counter-1];
          counter++;
        }
      }

      cout << endl;
    }

    if (i < cases - 1)
      cout << endl;
  }

  return 0;
}
