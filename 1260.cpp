#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
  int t, n, v;

  cin >> t;

  while (t--) {
    cin >> n;

    vector<int> values;
    int result = 0;

    bool first = true;
    while (n--) {
      cin >> v;

      if (!first) {
        for (int i = 0, sz = values.size(); i < sz; i++) {
          if (values[i] <= v) {
            result++;
          }
        }
      }

      first = false;
      values.push_back(v);
    }

    cout << result << endl;
  }
  
  return 0;
}
