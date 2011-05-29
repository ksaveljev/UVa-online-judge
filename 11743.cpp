#include <iostream>
#include <string>
using namespace std;

int digits_sum (int n) {
  int result = 0;

  while (n) {
    result += n % 10;
    n /= 10;
  }

  return result;
}

int main(void) {
  int n;
  string input, tmp;

  cin >> n;

  while (n--) {
    input = "";
    for (int i = 0; i < 4; i++) {
      cin >> tmp;
      input += tmp;
    }

    int sum = 0;

    for (int i = 0, sz = input.size(); i < sz; i++) {
      if (i % 2 == 0) {
        sum += digits_sum((input[i]-'0')*2);
      } else {
        sum += input[i] - '0';
      }
    }

    if (sum % 10 == 0) {
      cout << "Valid" << endl;
    } else {
      cout << "Invalid" << endl;
    }
  }

  return 0;
}
