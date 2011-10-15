#include <iostream>
#include <string>
using namespace std;

int compare(string& a, string b) {
  int result = 0;

  for (int i = 0; i < 3; i++) {
    if (a[i] == b[i]) {
      result += 1;
    }
  }

  return result;
}

int main(void)
{
  int t;
  string input;

  cin >> t;
  cin.ignore(100, '\n');

  while (t--) {
    getline(cin, input);
    
    if (input.size() == 3) {
      if (compare(input, "two") >= 2) {
        cout << 2 << endl;
      } else {
        cout << 1 << endl;
      }
    } else {
      cout << 3 << endl;
    }
  }
  
  return 0;
}
