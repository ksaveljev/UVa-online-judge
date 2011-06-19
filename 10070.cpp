#include <iostream>
#include <string>
#include <sstream>
using namespace std;

bool is_leap(const string &y) {
  if (y.size() < 9) {
    stringstream ss;
    ss << y;
    int year;
    ss >> year;
    return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
  } else {
    int last_two = int(y[y.size()-2] - '0')*10 + int(y[y.size()-1]-'0');
    if (last_two == 0) {
      last_two = int(y[y.size()-4] - '0')*10 + int(y[y.size()-3]-'0');
      return last_two % 4 == 0;
    } else {
      return last_two % 4 == 0;
    }
  }
}

bool is_hulu(const string &y) {
  int sum = 0;
  if (y[y.size()-1] != '5' && y[y.size()-1] != '0')
    return false;

  for (int i = 0, sz = y.size(); i < sz; i++)
    sum += int(y[i] -'0');

  return sum % 3 == 0;
}

bool is_bulu(const string &y) {
  if (y[y.size()-1] != '5' && y[y.size()-1] != '0')
    return false;

  int sum1, sum2;
  sum1 = sum2 = 0;

  for (int i = 0, sz = y.size(); i < sz; i += 2)
    sum1 += int(y[i] - '0');

  for (int i = 1, sz = y.size(); i < sz; i += 2)
    sum2 += int(y[i] - '0');

  return (sum1-sum2) % 11 == 0;
}

int main(void) {
  string input;
  int counter = 0;
  bool leap, hulu, bulu;

  while (getline(cin, input)) {
    leap = is_leap(input);
    hulu = is_hulu(input);
    bulu = is_bulu(input) && leap;

    if (counter > 0)
      cout << endl;

    counter++;

    if (leap)
      cout << "This is leap year." << endl;

    if (hulu)
      cout << "This is huluculu festival year." << endl;

    if (bulu)
      cout << "This is bulukulu festival year." << endl;

    if (!leap && !hulu && !bulu)
      cout << "This is an ordinary year." << endl;
  }

  return 0;
}
