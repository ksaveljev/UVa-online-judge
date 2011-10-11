#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

struct guess {
  int code;
  int perfect;
  int correct;
};

pair<int,int> compare_code_and_guess(int code, int guess) {
  int c[4] = {0,0,0,0};
  int g[4] = {0,0,0,0};

  int counter = 0;
  while (code) {
    c[counter] = code % 10;
    code /= 10;
    counter++;
  }

  counter = 0;
  while (guess) {
    g[counter] = guess % 10;
    guess /= 10;
    counter++;
  }

  int perfect = 0;

  for (int i = 0; i < 4; i++) {
    if (c[i] == g[i]) {
      c[i] = g[i] = -1;
      perfect++;
    }
  }

  int correct = 0;

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (c[i] == g[j] && c[i] != -1) {
        c[i] = g[j] = -1;
        correct++;
      }
    }
  }

  return make_pair(perfect, correct);
}

bool code_matches_guesses(int code, vector<guess>& guesses) {
  for (int i = 0, sz = guesses.size(); i < sz; i++) {
    pair<int,int> matches = compare_code_and_guess(code, guesses[i].code);
    if (matches.first != guesses[i].perfect || matches.second != guesses[i].correct) {
      return false;
    }
  }

  return true;
}

int main(void)
{
  int n, guesses_num;
  vector<guess> guesses;
  char delimiter;

  cin >> n;

  while (n--) {
    guesses.clear();

    cin >> guesses_num;

    while (guesses_num--) {
      guess tmp;
      cin >> tmp.code >> tmp.perfect >> delimiter >> tmp.correct;
      guesses.push_back(tmp);
    }

    vector<int> result;

    for (int i = 0; i < 10000; i++) {
      if (code_matches_guesses(i, guesses)) {
        result.push_back(i);
      }
    }

    if (result.empty()) {
      cout << "impossible" << endl;
    } else if (result.size() > 1) {
      cout << "indeterminate" << endl;
    } else {
      cout << setw(4) << setfill('0') << result[0] << endl;
    }
  }
  
  return 0;
}
