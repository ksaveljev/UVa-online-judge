#include <iostream>
#include <string>
#include <set>
using namespace std;

set<string> all;
bool taken[6];
char colors[6] = { 'R', 'G', 'B', 'Y', 'O', 'V' };

void generate(int depth, string result) {
  if (depth == 4) {
    all.insert(result);
    return;
  }

  for (int i = 0; i < 6; i++) {
    if (taken[i]) {
      continue;
    }

    taken[i] = true;
    generate(depth + 1, result + colors[i]);
    taken[i] = false;
  }
}

void generate_all_possible_strings() {
  for (int i = 0; i < 6; i++) {
    taken[i] = false;
  }

  generate(0, "");
}

pair<int,int> compare(string& guess, const string& s) {
  pair<int,int> result = make_pair(0,0);

  bool guess_taken[4] = {false};
  bool s_taken[4] = {false};

  for (int i = 0; i < 4; i++) {
    if (guess[i] == s[i]) {
      result.first++;
      guess_taken[i] = true;
      s_taken[i] = true;
    }
  }

  for (int i = 0; i < 4; i++) {
    if (guess_taken[i]) {
      continue;
    }
    for (int j = 0; j < 4; j++) {
      if (s_taken[j]) {
        continue;
      }

      if (guess[i] == s[j]) {
        result.second++;
        guess_taken[i] = true;
        s_taken[j] = true;
      }
    }
  }

  return result;
}

set<string> possible_matches(string& guess, int n1, int n2, set<string>& strings) {
  set<string> result;

  for (set<string>::iterator it = strings.begin(); it != strings.end(); it++) {
    pair<int,int> n = compare(guess, *it);
    if (n.first == n1 && n.second == n2) {
      result.insert(*it);
    }
  }

  return result;
}

int main(void)
{
  int t, n1, n2;
  string guess;

  generate_all_possible_strings();

  cin >> t;

  while (t--) {
    cin >> guess >> n1 >> n2;
    set<string> matches = possible_matches(guess, n1, n2, all);
    cin >> guess >> n1 >> n2;
    set<string> matches2 = possible_matches(guess, n1, n2, matches);

    if (matches2.empty()) {
      cout << "Cheat" << endl;
    } else {
      cout << "Possible" << endl;
    }
  }
  
  return 0;
}
