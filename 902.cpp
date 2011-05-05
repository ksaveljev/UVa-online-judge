#include <iostream>
#include <map>
#include <string>
using namespace std;

unsigned int jenkins_one_at_a_time_hash(const string &input, int start, int n) {
  unsigned int hash = 0;

  for (int i = 0; i < n; i++) {
    hash += input[start+i];
    hash += (hash << 10);
    hash ^= (hash >> 6);
  }

  hash += (hash << 3);
  hash ^= (hash >> 11);
  hash += (hash << 15);

  return hash;
}

struct result {
  string s;
  int count;
  result() : count(0) {}
};

int main(void) {
  int n;
  string input;
  unsigned int hash;
  map<unsigned int,int> m;
  
  while (cin >> n >> input) {
    m.clear();
    result best;

    for (int i = 0, sz = input.size(); i + n - 1 < sz; i++) {
      hash = jenkins_one_at_a_time_hash(input, i, n);
      if (m.find(hash) == m.end()) {
        m[hash] = 1;
      } else {
        m[hash] += 1;
      }

      if (m[hash] > best.count) {
        best.count = m[hash];
        best.s = string(input.begin() + i, input.begin() + i + n);
      }
    }

    cout << best.s << endl;
  }

  return 0;
}
