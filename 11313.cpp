#include <iostream>
using namespace std;

int main(void) {
  int t;
  int n, m;

  cin >> t;

  while (t--) {
    cin >> n >> m;

    if (m-1 == 1) {
      cout << n/(m-1) - 1 << endl;
    } else if (n % (m-1) == 1) {
      cout << n/(m-1) << endl;
    } else {
      cout << "cannot do this" << endl;
    }
  }

  return 0;
}
