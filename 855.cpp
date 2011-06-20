#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
  int t, r, c, f;
  int streets[50000];
  int avenues[50000];

  cin >> t;

  while (t--) {
    cin >> r >> c >> f;

    for (int i = 0; i < f; i++) {
      cin >> streets[i] >> avenues[i];
    }

    sort(streets, streets + f);
    sort(avenues, avenues + f);

    pair<int,int> result;

    result.first = streets[(f-1)/2];
    result.second = avenues[(f-1)/2];

    cout << "(Street: " << result.first << ", Avenue: " << result.second << ")" << endl;
  }

  return 0;
}
