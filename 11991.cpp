#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main(void) {
  int n, m, v, k;

  while (cin >> n >> m) {
    map<int, vector<int> > array;

    for (int i = 1; i <= n; i++) {
      cin >> v;
      if (array.find(v) == array.end()) {
        vector<int> tmp;
        array[v] = tmp;
      }
      array[v].push_back(i);
    }

    for (int i = 0; i < m; i++) {
      cin >> k >> v;

      if (array[v].size() < k) {
        cout << 0 << endl;
      } else {
        cout << array[v][k-1] << endl;
      }
    }
  }

  return 0;
}
