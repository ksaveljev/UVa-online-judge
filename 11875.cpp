#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
  int t, n;
  int age[15];

  cin >> t;

  for (int i = 0; i < t; i++) {
    cin >> n;
    for (int j = 0; j < n; j++)
      cin >> age[j];

    sort(age, age + n);

    cout << "Case " << i+1 << ": " << age[n/2] << endl;
  }

  return 0;
}
