#include <iostream>
using namespace std;

int main(void) {
  int t;
  char c;
  int rows, columns;
  int result;

  cin >> t;

  while (t--) {
    cin >> c >> rows >> columns;

    switch (c) {
      case 'r':
        cout << min(rows, columns) << endl;
        break;
      case 'k':
        result = 0;
        for (int i = 0; i < rows; i++) {
          for (int j = (i % 2 == 0 ? 0 : 1); j < columns; j += 2) {
            result++;
          }
        }
        cout << result << endl;
        break;
      case 'K':
        result = 0;
        for (int i = 0; i < rows; i += 2) {
          for (int j = 0; j < columns; j+=2) {
            result++;
          }
        }
        cout << result << endl;
        break;
      case 'Q':
        cout << min(rows, columns) << endl;
        break;
    }
  }

  return 0;
}
