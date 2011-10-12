#include <iostream>
using namespace std;

bool is_symmetric(long matrix[101][101], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (matrix[i][j] != matrix[n-i-1][n-j-1]) {
        return false;
      }
    }
  }

  return true;
}

int main(void)
{
  int t, n;
  char tmp;
  long matrix[101][101];

  cin >> t;

  for (int case_num = 1; case_num <= t; case_num++) {
    cin >> tmp >> tmp >> n; // example input: N = 4

    bool ok = true;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> matrix[i][j];
        if (matrix[i][j] < 0) {
          ok = false;
        }
      }
    }

    cout << "Test #" << case_num << ": ";

    if (ok && is_symmetric(matrix, n)) {
      cout << "Symmetric." << endl;
    } else {
      cout << "Non-symmetric." << endl;
    }
  }
  
  return 0;
}
