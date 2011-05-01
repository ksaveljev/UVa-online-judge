#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(void) {
  int cases;
  string a, b;

  cin >> cases;
  cin.ignore(100, '\n');

  for (int i = 0; i < cases; i++) {
    getline(cin, a);
    getline(cin, b);

    cout << "Case " << i + 1 << ": ";

    if (a == b)
      cout << "Yes";
    else {
      stringstream ss;
      ss << a;
      string tmp1 = "";
      while (ss >> a)
        tmp1 += a;

      ss.clear();
      ss.str(b);
      string tmp2 = "";
      while (ss >> b)
        tmp2 += b;

      if (tmp1 == tmp2)
        cout << "Output Format Error";
      else
        cout << "Wrong Answer";
    }


    cout << endl;
  }

  return 0;
}
