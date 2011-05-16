#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct racer {
  string name;
  int min, sec, ms;
};

bool compare_names(string a, string b) {
  transform(a.begin(), a.end(), a.begin(), ::tolower);
  transform(b.begin(), b.end(), b.begin(), ::tolower);

  return a < b;
}

bool theTruthIsOutThere(const racer &a, const racer &b) {
  if (a.min == b.min) {
    if (a.sec == b.sec) {
      if (a.ms == b.ms)
        return compare_names(a.name, b.name);
      else
        return a.ms < b.ms;
    }

    return a.sec < b.sec;
  }

  return a.min < b.min;
}

int main(void) {
  int n;
  int t;
  char c;
  string name;
  racer tmp;
  vector<racer> racers;

  while (cin >> n) {
    cin.ignore(100, '\n');
    racers.clear();

    for (int i = 0; i < n; i++ ) {
      name = "";
      while (cin >> c) {
        if (c == ':')
          break;

        name += c;
      }

      tmp.name = name;
      // using name as placeholder
      cin >> t >> name;
      tmp.min = t;
      cin >> t >> name;
      tmp.sec = t;
      cin >> t >> name;
      tmp.ms = t;

      cin.ignore(100, '\n');

      racers.push_back(tmp);
    }

    // get blank line
    getline(cin, name);

    sort(racers.begin(), racers.end(), theTruthIsOutThere);

    for (int i = 0, sz = racers.size(); i < sz; i++) {
      if (i % 2 == 0) {
        cout << "Row " << i/2 + 1 << endl;
      }

      cout << racers[i].name << endl;
    }

    cout << endl;
  }

  return 0;
}
