#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct manufacturer {
  string name;
  int low, high;
};

int main(void)
{
  int t, d, low, high, q, p;
  string name;
  manufacturer tmp;
  vector<manufacturer> manufacturers;

  cin >> t;

  while (t--) {
    cin >> d;

    manufacturers.clear();

    while (d--) {
      cin >> tmp.name >> tmp.low >> tmp.high;
      manufacturers.push_back(tmp);
    }

    cin >> q;

    while (q--) {
      cin >> p;

      bool ok = false;
      string result = "";

      for (int i = 0, sz = manufacturers.size(); i < sz; i++) {
        if (manufacturers[i].low <= p && manufacturers[i].high >= p) {
          if (result == "") {
            ok = true;
            result = manufacturers[i].name;
          } else if (result != "") {
            ok = false;
            break;
          }
        }
      }

      if (ok) {
        cout << result << endl;
      } else {
        cout << "UNDETERMINED" << endl;
      }
    }

    if (t) {
      cout << endl;
    }
  }
  
  return 0;
}
