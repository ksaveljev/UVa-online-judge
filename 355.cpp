#include <iostream>
#include <string>
using namespace std;

string convert(long long n, int base) {
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

long long any2dec(const string &s, int base) {
  char c;
  size_t found;
  unsigned long long result = 0;
  string NUMS = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

  for (int i = 0, sz = s.size(); i < sz; i++) {
    found = NUMS.find(s[i]);

    if (found == string::npos || int(found) >= base)
      return -1;

    result = result * base + int(found);
  }

  return result;
}

int main(void) {
  int a, b;
  string num;

  while (cin >> a >> b >> num) {
    long long tmp = any2dec(num, a);
    if (tmp == -1) { 
      cout << num << " is an illegal base " << a << " number" << endl;
      continue;
    }

    cout << num << " base " << a << " = " << convert(tmp, b) << " base " << b << endl;
  }

  return 0;
}
