#include <iostream>
using namespace std;

int main(void)
{
  int n;
  int h1, m1, h2, m2;
  pair<int,int> meeting, wife;
  char delim;

  cin >> n;

  for (int case_num = 0; case_num < n; case_num++) {
    cin >> h1 >> delim >> m1 >> h2 >> delim >> m2;

    wife.first = h1 * 60 + m1;
    wife.second = h2 * 60 + m2;

    cin >> h1 >> delim >> m1 >> h2 >> delim >> m2;

    meeting.first = h1 * 60 + m1;
    meeting.second = h2 * 60 + m2;

    cout << "Case " << case_num+1 << ": ";

    if (meeting.first > wife.second || meeting.second < wife.first) {
      cout << "Hits Meeting" << endl;
    } else {
      cout << "Mrs Meeting" << endl;
    }
  }
  
  return 0;
}
