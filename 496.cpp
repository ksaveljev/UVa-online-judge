#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

void solve(const vector<int> &a, const vector<int> &b) {
  int counter = 0;

  for (int i = 0, sz = a.size(); i < sz; i++) {
    for (int j = 0, sz2 = b.size(); j < sz2; j++) {
      if (a[i] == b[j])
        counter++;
    }
  }

  if (counter == a.size() && counter == b.size()) {
    cout << "A equals B" << endl;
  } else if (counter == a.size()) {
    cout << "A is a proper subset of B" << endl;
  } else if (counter == b.size()) {
    cout << "B is a proper subset of A" << endl;
  } else if (counter == 0) {
    cout << "A and B are disjoint" << endl;
  } else {
    cout << "I'm confused!" << endl;
  }
}

int main(void) {
  int tmp;
  string input;
  vector<int> a, b;
  stringstream ss;

  while(getline(cin, input)) {
    a.clear();
    b.clear();

    ss.clear();
    ss.str(input);

    while (ss >> tmp)
      a.push_back(tmp);

    getline(cin, input);
    ss.clear();
    ss.str(input);

    while (ss >> tmp)
      b.push_back(tmp);

    solve(a, b);
  }

  return 0;
}
