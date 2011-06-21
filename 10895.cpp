#include <iostream>
#include <vector>
using namespace std;

int main(void) {
  int m, n, r, value;
  int cols[10010];
  vector< vector< pair<int,int> > > matrix;

  while (cin >> m >> n) {
    matrix.clear();

    for (int i = 0; i < n; i++) {
      vector< pair<int,int> > tmp;
      matrix.push_back(tmp);
    }

    for (int i = 1; i <= m; i++) {
      cin >> r;

      for (int j = 0; j < r; j++) {
        cin >> cols[j];
      }

      for (int j = 0; j < r; j++) {
        cin >> value;
        matrix[cols[j]-1].push_back(make_pair(i, value));
      }
    }

    cout << n << " " << m << endl;
    for (int i = 0; i < n; i++) {
      int sz = matrix[i].size();
      cout << sz;
      for (int j = 0; j < sz; j++)
        cout << " " << matrix[i][j].first;
      cout << endl;
      for (int j = 0; j < sz; j++) {
        if (j > 0) cout << " ";
        cout << matrix[i][j].second;
      }
      cout << endl;
    }
  }

  return 0;
}
