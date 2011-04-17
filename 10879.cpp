#include <iostream>
using namespace std;

int main(void) {
  int n, k;
  int counter;

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> k;

    counter = 0;
    
    cout << "Case #" << i+1 << ": " << k << " = ";

    for (int a = 2; a < k/2; a++) {
      if (k % a == 0) {
        counter++;
        if (counter == 2)
          cout << " = ";
        cout << a << " * " << k / a;

        if (counter == 2) {
          cout << endl;
          break;
        }
      }
    }
  }

  return 0;
}
