#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

int main(void) {
  int words = 0;
  map<string,int> count;
  string input;

  while (getline(cin, input)) {
    if (input == "****END_OF_INPUT****")
      break;

    if (input == "****END_OF_TEXT****") {
      double e_max = log10(words);
      double e_t = 0;

      for (typeof(count.begin()) it = count.begin(); it != count.end(); it++) {
        e_t += it->second * (log10(words) - log10(it->second));
      }

      e_t /= words;

      double e_rel = e_t * 100 / e_max;

      printf("%d %.1lf %.0lf\n", words, e_t, e_rel);

      words = 0;
      count.clear();
      continue;
    }

    transform(input.begin(), input.end(), input.begin(), ::tolower);

    for (int i = 0, sz = input.size(); i < sz; i++)
      if (input[i] == '.' || input[i] == ',' || input[i] == ':' || input[i] == ';' || input[i] == '!' || input[i] == '?' || input[i] == '"' || input[i] == '(' || input[i] == ')' || input[i] == '\t' || input[i] == '\n')
        input[i] = ' ';

    stringstream ss(input);
    while (ss >> input) {
      if (count.find(input) == count.end())
        count[input] = 1;
      else
        count[input] += 1;

      words++;
    }
  }

  return 0;
}
