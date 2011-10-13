#include <iostream>
using namespace std;

void count_digits(int number, int* result) {
  while (number > 0) {
    result[number % 10] += 1;
    number /= 10;
  }
}

int main(void)
{
  int t, n;

  cin >> t;

  int* result;
  result = new int[10];

  while (t--) {
    cin >> n;

    for (int i = 0; i < 10; i++) {
      result[i] = 0;
    }

    for (int i = 1; i <= n; i++) {
      count_digits(i, result);
    }

    for (int i = 0; i < 10; i++) {
      if (i > 0) {
        cout << " ";
      }
      cout << result[i];
    }
    cout << endl;
  }

  delete [] result;
  
  return 0;
}
