#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(void) {
  int m, n;
  string word;
  int cost;
  int result;
  map<string,int> words;

  cin >> m >> n;

  for (int i = 0; i < m; i++) {
    cin >> word >> cost;
    words[word] = cost;
  }

  result = 0;

  while (n) {
    cin >> word;

    if (word == ".") {
      cout << result << endl;
      n--;
      result = 0;
      continue;
    }

    if (words.find(word) != words.end())
      result += words[word];
  }

  return 0;
}
