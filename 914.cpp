#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

bool is_prime(int n) {
  for (int i = 3, sq = sqrt(n); i <= sq; i += 2) {
    if (n % i == 0)
      return false;
  }

  return true;
}

void add_difference(vector< pair<int,int> > &v, int diff) {
  bool found = false;

  for (int i = 0, sz = v.size(); i < sz; i++) {
    if (v[i].first == diff) {
      found = true;
      v[i].second++;
      break;
    }
  }

  if (!found) {
    v.push_back(make_pair(diff, 1));
  }
}

bool theTruthIsOutThere(const pair<int,int> &a, const pair<int,int> &b) {
  return a.second > b.second;
}

int main(void) {
  int t;
  int start, end;
  vector<int> primes;
  vector< pair<int,int> > result;

  primes.push_back(2);

  for (int i = 3; i < 1000000; i += 2)
    if (is_prime(i))
      primes.push_back(i);

  cin >> t;

  while (t--) {
    cin >> start >> end;

    result.clear();

    int prev = -1;
    for (int i = 0, sz = primes.size(); i < sz; i++) {
      if (primes[i] >= start && primes[i] <= end) {
        if (prev == -1)
          prev = primes[i];
        else {
          add_difference(result, primes[i] - prev);
          prev= primes[i];
        }
      }
    }

    sort(result.begin(), result.end(), theTruthIsOutThere);

    if (result.size() == 0) {
      cout << "No jumping champion" << endl;
    } else if (result.size() == 1) {
      cout << "The jumping champion is " << result[0].first << endl;
    } else {
      if (result[0].second > result[1].second) {
        cout << "The jumping champion is " << result[0].first << endl;
      } else {
        cout << "No jumping champion" << endl;
      }
    }
  }

  return 0;
}
