#include <iostream>
#include <string>
using namespace std;

int main(void) {
  int n;
  string input;

  cin >> n;

  while (n--) {
    cin >> input;

    if (input == "1" || input == "4" || input == "78") {
      cout << "+" << endl;
    } else if (input.size() > 1 && input[input.size()-2] == '3' && input[input.size()-1] == '5') {
      cout << "-" << endl;
    } else if (input[0] == '9' && input[input.size()-1] == '4') {
      cout << "*" << endl;
    } else if (input.size() > 2 && input[0] == '1' && input[1] == '9' && input[2] == '0') {
      cout << "?" << endl;
    }
  }

  return 0;
}
