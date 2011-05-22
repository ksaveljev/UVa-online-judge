#include <iostream>
using namespace std;

int main(void) {
  int start;
  int a, b, c;
  int result;

  int angle = 9;

  while (cin >> start >> a >> b >> c) {
    if (start == 0 && a == 0 && b == 0 && c == 0)
      break;
    
    result = 1080;
    
    if (a > start) {
      result += (start + 40 - a) * angle;
    } else {
      result += (start - a) * angle;
    }

    if (b < a) {
      result += (40 - a + b) * angle;
    } else {
      result += (b - a) * angle;
    }

    if (c > b) {
      result += (b + 40 - c) * angle;
    } else {
      result += (b - c) * angle;
    }

    cout << result << endl;
  }

  return 0;
}
