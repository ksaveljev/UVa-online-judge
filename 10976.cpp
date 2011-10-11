#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool theTruthIsOutThere(const pair<int,int>& a, const pair<int,int>& b) {
  return a.first > b.first;
}

int main(void)
{
  int k;
  vector< pair<int,int> > result;

  while (cin >> k) {
    result.clear();

    for (int i = 1; i <= k; i++) {
      if ((k + i) * k % i == 0) {
        result.push_back(make_pair((k+i)*k/i, k+i));
      }
    }

    sort(result.begin(), result.end(), theTruthIsOutThere);

    cout << result.size() << endl;
    for (int i = 0, sz = result.size(); i < sz; i++) {
      cout << "1/" << k << " = " << "1/" << result[i].first << " + 1/" << result[i].second << endl;
    }
  }
  
  return 0;
}
