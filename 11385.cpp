#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool theTruthIsOutThere(const pair<int,char> &a, const pair<int,char> &b) {
  return a.first < b.first;
}

int main(void) {
  int cases;
  int n;
  string input;
  vector< pair<int,char> > v;

  cin >> cases;

  while (cases--) {
    cin >> n;

    v.clear();
    vector<int> nums(n);

    for (int i = 0; i < n; i++)
      cin >> nums[i];

    cin.ignore(100, '\n');

    getline(cin ,input);

    n = 0;
    for (int i = 0, sz = input.size(); i < sz && n < nums.size(); i++) {
      if (input[i] >= 'A' && input[i] <= 'Z') {
        v.push_back(make_pair(nums[n], input[i]));
        n++;
      }
    }

    sort(v.begin(), v.end(), theTruthIsOutThere);

    n = 0;
    int a = 0;
    int b = 1;
    int r;
    while (n != v.size()) {
      r = a + b;
      a = b;
      b = r;

      if (v[n].first == r) {
        cout << v[n].second;
        n++;
      } else {
        cout << " ";
      }
    }
    
    cout << endl;
  }

  return 0;
}
