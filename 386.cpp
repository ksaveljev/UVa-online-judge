#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

struct result {
  int a, b, c, d;
};

bool theTruthIsOutThere(const result &a, const result &b) {
  return a.a == b.a ? a.b < b.b : a.a < b.a;
}

int main(void) {
  vector<result> results;
  result tmp;
  map<int,int> memo;
  map<int,int> cubes;

  for (int a = 2; a < 201; a++) {
    cubes[a*a*a] = a;
    memo[a] = a * a * a;
  }

  for (int b = 2; b < 201; b++) {
    for (int c = b; c < 201; c++) {
      for (int d = c; d < 201; d++) {
        if (cubes.find(memo[b] + memo[c] + memo[d]) != cubes.end()) {
          tmp.a = cubes[memo[b] + memo[c] + memo[d]];
          tmp.b = b;
          tmp.c = c;
          tmp.d = d;
          results.push_back(tmp);
        }
      }
    }
  }

  sort(results.begin(), results.end(), theTruthIsOutThere);

  for (int i = 0, sz = results.size(); i < sz; i++)
    cout << "Cube = " << results[i].a << ", Triple = (" << results[i].b << "," << results[i].c << "," << results[i].d << ")" << endl;

  return 0;
}
