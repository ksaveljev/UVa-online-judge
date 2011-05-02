#include <iostream>
#include <string>
using namespace std;

string negativetwobase(int n) {
  string result = "";
  int remainder;

  if (n == 0)
    return "0";

  while (n != 0) {
    remainder = n % -2;
    n /= -2;
    if (remainder < 0) {
      n += 1;
      remainder += 2;
    }
    result += (char)('0' + remainder);
  }

  return string(result.rbegin(), result.rend());
}

int main(void) {
  int cases;
  int num;

  cin >> cases;

  for (int i = 0; i < cases; i++) {
    cout << "Case #" << i+1 << ": ";

    cin >> num;

    cout << negativetwobase(num) << endl;
  }
}
