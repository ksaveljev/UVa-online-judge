#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(void) {
  int t, n, d;
  string input;
  map<string,int>::iterator it;

  cin >> t;

  for (int c = 0; c < t; c++) {
    cin >> n;

    map<string,int> subjects;

    while (n--) {
      cin >> input >> d;
      subjects[input] = d;
    }

    cin >> d >> input;

    it = subjects.find(input);

    cout << "Case " << c+1 << ": ";
    if (it != subjects.end() && subjects[input] <= d) {
      cout << "Yesss" << endl;
    } else if (it != subjects.end() && subjects[input] <= d + 5) {
      cout << "Late" << endl;
    } else {
      cout << "Do your own homework!" << endl;
    }
  }

  return 0;
}
