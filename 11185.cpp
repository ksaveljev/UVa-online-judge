#include <iostream>
#include <string>
using namespace std;

string convert(int n, int base) {
  if (n == 0)
    return "0";

  char NUMS[] = "0123456789ABCDEF";
  string result = "";

  do {
    result.push_back(NUMS[n % base]);
    n /= base;
  } while (n);

  return string(result.rbegin(), result.rend());
}

int main(void) {
  int n;

  while (cin >> n) {
    if (n < 0)
      break;
    cout << convert(n, 3) << endl;
  }

  return 0;
}
