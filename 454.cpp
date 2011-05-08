#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct anagram {
  string word;
  string chars;
};

bool theTruthIsOutThere(const anagram &a, const anagram &b) {
  return a.word < b.word;
}

bool trustNoOne(const pair<string,string> &a, const pair<string,string> &b) {
  if (a.first == b.first) {
    return a.second < b.second;
  }

  return a.first < b.first;
}

int main(void) {
  int cases;
  string input;
  int count;
  anagram words[110];
  vector< pair<string,string> > result;

  cin >> cases;
  cin.ignore(100, '\n');
  cin.ignore(100, '\n');

  while (cases--) {
    count = 0;
    result.clear();

    while (getline(cin, input)) {
      if (input == "")
        break;

      words[count].word = input;
      words[count].chars = "";
      for (int i = 0, sz = input.size(); i < sz; i++) {
        if (input[i] == ' ')
          continue;

        words[count].chars += input[i];
      }

      sort(words[count].chars.begin(), words[count].chars.end(), less<char>());

      count++;
    }

    sort(words, words + count, theTruthIsOutThere);

    for (int i = 0; i < count - 1; i++) {
      for (int j = i + 1; j < count; j++) {
        if (words[i].chars == words[j].chars) {
          result.push_back(make_pair(words[i].word, words[j].word));
        }
      }
    }

    sort(result.begin(), result.end(), trustNoOne);

    for (int i = 0, sz = result.size(); i < sz; i++) {
      cout << result[i].first << " = " << result[i].second << endl;
    }

    if (cases)
      cout << endl;
  }

  return 0;
}
