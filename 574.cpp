#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int t;
int n;
int taken;
int nums[12];
vector<int> result;

bool same(int a, int b) {
  if (__builtin_popcount(a) != __builtin_popcount(b))
    return false;

  int v1, v2;
  int count = __builtin_popcount(a);

  while (count) {
    for (int i = 0; i < 12; i++) {
      if ((a & 1<<i) != 0) {
        v1 = nums[i];
        a &= ~(1<<i);
        break;
      }
    }

    for (int i = 0; i < 12; i++) {
      if ((b & 1<<i) != 0) {
        v2 = nums[i];
        b &= ~(1<<i);
        break;
      }
    }

    count--;

    if (v1 != v2)
      return false;
  }

  return true;
}

void solve(int element, int sum) {
  if (sum == t) {
    bool ok = true;

    for (int i = 0, sz = result.size(); i < sz; i++) {
      if (same(result[i], taken)) {
        ok = false;
        break;
      }
    }

    if (ok)
      result.push_back(taken);

    return;
  }

  if (element == n) {
    return;
  }

  for (int i = element; i < n; i++) {
    if (sum + nums[i] <= t) {
      taken |= 1 << i; // set bit
      solve(i + 1, sum + nums[i]);
      taken &= ~(1 << i); // clear bit
    }
  }
}

bool theTruthIsOutThere(int a, int b) {
  int bita, bitb;

  for (int i = 11; i >= 0; i--) {
    bita = a & (1 << i);
    bitb = b & (1 << i);

    if (a == b)
      continue;

    return a > b;
  }
}

void print_result(int a) {
  bool first = true;

  for (int i = 11; i >= 0; i--) {
    if ((a & (1<<i)) != 0) {
      if (!first)
        cout << "+";
      cout << nums[i];
      first = false;
    }
  }

  cout << endl;
}

int main(void) {
  while (cin >> t >> n) {
    if (n == 0) 
      break;

    taken = 0;
    result.clear();

    for (int i = n - 1; i >= 0; i--)
      cin >> nums[i];

    solve(0, 0);

    cout << "Sums of " << t << ":" << endl;

    if (result.empty()) {
      cout << "NONE" << endl;
      continue;
    }

    sort(result.begin(), result.end(), theTruthIsOutThere);

    for (int i = 0, sz = result.size(); i < sz; i++) {
      print_result(result[i]);
    }
  }

  return 0;
}
