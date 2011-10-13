#include <iostream>
using namespace std;

int main(void)
{
  int n;
  int answers[101];

  answers[0] = 0;
  for (int i = 1; i < 101; i++) {
    answers[i] = i * i + answers[i-1];
  }

  while (cin >> n) {
    if (!n) {
      break;
    }

    cout << answers[n] << endl;
  }
  
  return 0;
}
