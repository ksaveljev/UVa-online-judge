#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <cmath>
using namespace std;

void split_string(const string &s, vector<int> &v) {
  istringstream in(s);
	v.clear();
	copy(istream_iterator<int>(in), istream_iterator<int>(), back_inserter(v));
}

int main(void) {
  string input;
  vector<int> c;
  vector<int> x;

  while (getline(cin, input)) {
    split_string(input, c);
    getline(cin,input);
    split_string(input, x);

    int n = c.size() - 1;

    for (int i = 0, sz = x.size(); i < sz; i++) {
      if (i > 0)
        cout << " ";

      int result = 0;
      for (int j = 0, sz2 = c.size(); j < sz2; j++) {
        result += c[j] * pow(x[i], n - j);
      }
      cout << result;
    }
    cout << endl;
  }

  return 0;
}
