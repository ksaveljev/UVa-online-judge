#include <iostream>
#include <string>
#include <map>
#include <cstdlib>
using namespace std;

bool is_oudler(const string &s) {
  return s == "one" || s == "twenty-one" || s == "fool";
}

int get_limit(int oudlers) {
  switch (oudlers) {
    case 0:
      return 56;
      break;
    case 1:
      return 51;
      break;
    case 2:
      return 41;
      break;
    case 3:
      return 36;
      break;
  }
}

int main(void) {
  int t, n;
  string input;
  int oudlers;
  double collected;
  map<string,double> points;

  points["one"] = 4.5;
  points["ace"] = 0.5;
  points["two"] = 0.5;
  points["three"] = 0.5;
  points["four"] = 0.5;
  points["five"] = 0.5;
  points["six"] = 0.5;
  points["seven"] = 0.5;
  points["eight"] = 0.5;
  points["nine"] = 0.5;
  points["ten"] = 0.5;
  points["jack"] = 1.5;
  points["knight"] = 2.5;
  points["queen"] = 3.5;
  points["king"] = 4.5;
  points["eleven"] = 0.5;
  points["twelve"] = 0.5;
  points["thirteen"] = 0.5;
  points["fourteen"] = 0.5;
  points["fifteen"] = 0.5;
  points["sixteen"] = 0.5;
  points["seventeen"] = 0.5;
  points["eighteen"] = 0.5;
  points["nineteen"] = 0.5;
  points["twenty"] = 0.5;
  points["twenty-one"] = 4.5;
  points["fool"] = 4.5;


  cin >> t;

  for (int casenum = 0; casenum < t; casenum++) {
    cin >> n;

    if (casenum)
      cout << endl;

    oudlers = 0;
    collected = 0;

    for (int i = 0; i < n; i++) {
      cin >> input;

      if (is_oudler(input))
        oudlers++;

      collected += points[input];

      getline(cin, input);
    }

    int limit = get_limit(oudlers);
    int won = collected;

    cout << "Hand #" << casenum+1 << endl;
    cout << "Game " << (won >= limit ? "won" : "lost") << " by " << abs(won - limit) << " point(s)." << endl;
  }

  return 0;
}
