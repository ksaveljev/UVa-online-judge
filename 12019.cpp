#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(void) {
  int months[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
  map<int,string> m;

  m[0] = "Saturday";
  m[1] = "Sunday";
  m[2] = "Monday";
  m[3] = "Tuesday";
  m[4] = "Wednesday";
  m[5] = "Thursday";
  m[6] = "Friday";

  int cur_d = 0;

  int result[13][32];

  for (int i = 1; i <= 12; i++) {
    for (int j = 1; j <= months[i-1]; j++) {
      result[i][j] = cur_d;
      cur_d++;
      cur_d %= 7;
    }
  }

  int t;
  int mon, day;

  cin >> t;

  while (t--) {
    cin >> mon >> day;
    cout << m[result[mon][day]] << endl;
  }

  return 0;
}
