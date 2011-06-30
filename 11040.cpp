#include <iostream>
using namespace std;

int main(void)
{
  int t;

  cin >> t;

  while (t--) {
    int a[9][9] = {0};

    for (int i = 0; i < 5; i++) {
      for (int j = 0; j <= i; j++) {
        cin >> a[i*2][j*2];

        if (i > 0 && j > 0) {
          a[i*2][j*2-1] = (a[(i-1)*2][(j-1)*2] - (a[i*2][j*2] + a[i*2][j*2-2]))/2;
          a[i*2-1][j*2-1] = a[i*2][j*2] + a[i*2][j*2-1];
          a[i*2-1][j*2-2] = a[i*2][j*2-1] + a[i*2][j*2-2];
        }
      }
    }

    for (int i = 0; i < 9; i++) {
      for (int j = 0; j <= i; j++) {
        if (j > 0) {
          cout << " ";
        }
        cout << a[i][j];
      }
      cout << endl;
    }
  }
  
  return 0;
}
