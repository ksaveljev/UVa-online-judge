#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
  int input;
  int *n = new int[1000001];

  n[0] = 1;

  for (int i = 1; i < 1000001; i++) {
    n[i] = n[(int)floor(i - sqrt(i))] + n[(int)floor(log(i))] + n[(int)floor(i * sin(i) * sin(i))];
    n[i] %= 1000000;
  }

  while (cin >> input) {
    if (input == -1) {
      break;
    }
    cout << n[input] << endl;
  }


  delete [] n;
  
  return 0;
}
