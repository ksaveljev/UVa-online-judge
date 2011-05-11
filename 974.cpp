#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int num_len(int n) {
  if (n == 0)
    return 0;

  return log10(n) + 1;
}

bool is_kaprekar(int n) {
  int sq = n * n;
  int a, b;

  for (int i = 1, sz = num_len(sq); i < sz; i++) {
    a = sq / pow(10, i);
    b = sq % ((int)pow(10, i));

    if (a == 0 || b == 0)
      continue;

    if (a + b == n)
      return true;
  }
  
  return false;
}

int main(void) {
  int cases;
  bool found;
  int start, end;
  vector<int> kaprekar;

  for (int i = 2; i < 40001; i++) {
    if (is_kaprekar(i))
      kaprekar.push_back(i);
  }

  cin >> cases;

  for (int i = 0; i < cases; i++) {
    if (i > 0)
      cout << endl;

    cin >> start >> end;
    found = false;

    cout << "case #" << i + 1 << endl;
    for (int j = 0, sz = kaprekar.size(); j < sz; j++) {
      if (kaprekar[j] >= start && kaprekar[j] <= end) {
        found = true;
        cout << kaprekar[j] << endl;
      }
    }

    if (!found) {
      cout << "no kaprekar numbers" << endl;
    }
  }

  return 0;
}
