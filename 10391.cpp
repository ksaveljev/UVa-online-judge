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

int main(void) {
  int n = 0;
  string input;
  string *words = new string[120001];
  map<unsigned int,bool> m;
  unsigned int hash;

  while (cin >> words[n]) {
    hash = jenkins_one_at_a_time_hash(words[n], 0, words[n].size());
    m[hash] = true;
    n++;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 1; j < words[i].size() - 1; j++) {
      hash = jenkins_one_at_a_time_hash(words[i], 0, j);
      if (m.find(hash) != m.end()) {
        hash = jenkins_one_at_a_time_hash(words[i], j, words[i].size() - j);
        if (m.find(hash) != m.end()) {
          cout << words[i] << endl;
          break;
        }
      }
    }
  }

  delete [] words;

  return 0;
}
