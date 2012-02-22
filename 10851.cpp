#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(void)
{
  int n;
  string input;
  string hieroglyphs[10];

  cin >> n;

  while (n--) {
    getline(cin, input);

    for (int i = 0; i < 10; i++) {
      getline(cin, hieroglyphs[i]);
    }

    int m = hieroglyphs[0].size() - 2;

    for (int i = 0; i < m; i++) {
      char decoded = 0;

      for (int j = 0; j < 8; j++) {
        if (hieroglyphs[j+1][i+1] == '/') {
          continue;
        }

        decoded += pow(2, j);
      }

      cout << decoded;
    }

    cout << endl;
  }
  
  return 0;
}
