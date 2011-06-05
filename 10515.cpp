#include <iostream>
#include <string>
using namespace std;

int getN(const string &s) {
  if (s.size() == 1) {
    return s[0] - '0';
  } else {
    return (s[s.size()-2]-'0')*10 + s[s.size()-1] - '0';
  }
}

int main(void) {
  string a, b;

  while (cin >> a >> b) {
    if (a == "0" && b == "0")
      break;

    if (b == "0") {
      cout << 1 << endl;
      continue;
    }

    int m = a[a.size()-1] - '0';
    int n = getN(b);

    switch (m) {
      case 0:
        cout << 0 << endl;
        break;
      case 1:
        cout << 1 << endl;
        break;
      case 2:
        switch (n % 4) {
          case 1:
            cout << 2 << endl;
            break;
          case 2:
            cout << 4 << endl;
            break;
          case 3:
            cout << 8 << endl;
            break;
          case 0:
            cout << 6 << endl;
            break;
        }
        break;
      case 3:
        switch (n % 4) {
          case 1:
            cout << 3 << endl;
            break;
          case 2:
            cout << 9 << endl;
            break;
          case 3:
            cout << 7 << endl;
            break;
          case 0:
            cout << 1 << endl;
            break;
        }
        break;
      case 4:
        if (n % 2 != 0)
          cout << 4 << endl;
        else
          cout << 6 << endl;
        break;
      case 5:
        cout << 5 << endl;
        break;
      case 6:
        cout << 6 << endl;
        break;
      case 7:
        switch (n % 4) {
          case 1:
            cout << 7 << endl;
            break;
          case 2:
            cout << 9 << endl;
            break;
          case 3:
            cout << 3 << endl;
            break;
          case 0:
            cout << 1 << endl;
            break;
        }
        break;
      case 8:
        switch (n % 4) {
          case 1:
            cout << 8 << endl;
            break;
          case 2:
            cout << 4 << endl;
            break;
          case 3:
            cout << 2 << endl;
            break;
          case 0:
            cout << 6 << endl;
            break;
        }
        break;
      case 9:
        if (n % 2 != 0)
          cout << 9 << endl;
        else
          cout << 1 << endl;
        break;
    }
  }

  return 0;
}
