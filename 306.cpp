#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void)
{
  int n, k, keys[201], cycle[201];
  char output[201];
  string input;

  while (cin >> n) {
    if (n == 0) {
      break;
    }

    for (int i = 0; i < n; i++) {
      cin >> keys[i];
      keys[i] -= 1;
    }

    for (int i = 0; i < n; i++) {
      int result = 1;
      int current = keys[i];

      while (i != current) {
        result++;
        current = keys[current];
      }

      cycle[i] = result;
    }

    while (cin >> k) {
      if (k == 0) {
        break;
      }

      cin.get();

      getline(cin, input);

      while (input.size() < n) {
        input += " ";
      }

      for (int i = 0; i < n; i++) {
        int c = k % cycle[i];
        int pos = i;

        while (c--) {
          pos = keys[pos];
        }

        output[pos] = input[i];
      }

      cout << string(output, n) << endl;
    }

    cout << endl;
  }
  
  return 0;
}
