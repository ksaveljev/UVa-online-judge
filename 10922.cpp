#include <iostream>
#include <string>
using namespace std;

int main(void) {
  int n, sum, result, tmp;
  string input;

  while (cin >> input) {
    if (input == "0")
      break;

    result = 1;
    sum = 0;
    for (int i = 0, sz = input.size(); i < sz; i++) {
      sum += (input[i] - '0');
    }

    if (sum % 9 != 0) {
      cout << input << " is not a multiple of 9." << endl;
      continue;
    }
    
    while (sum != 9) {
      tmp = sum;
      sum = 0;

      while (tmp) {
        sum += tmp % 10;
        tmp /= 10;
      }

      result++;
    }

    cout << input << " is a multiple of 9 and has 9-degree " << result << "." << endl;
  }

  return 0;
}
