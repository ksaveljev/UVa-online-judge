#include <iostream>
#include <string>
using namespace std;

string conj[6] = {
  "eu        ",
  "tu        ",
  "ele/ela   ",
  "nos       ",
  "vos       ",
  "eles/elas "
};

string sufix[3][6] = {
{"o", "as", "a", "amos", "ais", "am"},
{"o", "es", "e", "emos", "eis", "em"},
{"o", "es", "e", "imos", "is", "em"}
};

int main(void) {
  bool first = true;
  string v1, v2;
  string root;
  int n;

  conj[3][1] = (char)243;
  conj[4][1] = (char)243;

  while (cin >> v1 >> v2) {
    if (!first)
      cout << endl;

    cout << v1 << " (to " << v2 << ")" << endl;

    if (v1.size() < 2) {
      cout << "Unknown conjugation" << endl;
      first = false;
      continue;
    }

    if (v1[v1.size()-2] == 'a' && v1[v1.size()-1] == 'r') {
      n = 0;
    } else if (v1[v1.size()-2] == 'e' && v1[v1.size()-1] == 'r') {
      n = 1;
    } else if (v1[v1.size()-2] == 'i' && v1[v1.size()-1] == 'r') {
      n = 2;
    } else {
      cout << "Unknown conjugation" << endl;
      first = false;
      continue;
    }

    root = string(v1.begin(), v1.begin() + v1.size() - 2);

    for (int i = 0; i < 6; i++) {
      cout << conj[i] << root << sufix[n][i] << endl;
    }

    first = false;
  }

  return 0;
}
