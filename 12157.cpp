#include <iostream>
using namespace std;

int main(void)
{
  int t, n, d;

  cin >> t;

  for (int case_num = 0; case_num < t; case_num++) {
    cin >> n;

    int mile = 0, juice = 0;

    while (n--) {
      cin >> d;
      mile += ((d / 30) + 1) * 10;
      juice += ((d / 60) + 1) * 15;
    }

    cout << "Case " << case_num + 1 << ": ";

    if (mile < juice) {
      cout << "Mile " << mile << endl;
    } else if (juice < mile) {
      cout << "Juice " << juice << endl;
    } else {
      cout << "Mile Juice " << mile << endl;
    }
  }
  
  return 0;
}
