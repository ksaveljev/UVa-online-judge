#include <iostream>
#include <string>
#include <set>
#include <sstream>
#include <algorithm>
using namespace std;

int main(void) {
  set<string> words;
  string input;
  string text = "";
  stringstream ss;
  bool hyphen = false;

  while (getline(cin, input)) {
    if (!hyphen)
      text += " ";
    if (input[input.size()-1] == '-') {
      for (int i = 0, sz = input.size(); i < sz - 1; i++)
        text += input[i];

      hyphen = true;
    } else {
      text += input;
      hyphen = false;
    }
  }

  for (int i = 0, sz = text.size(); i < sz; i++) {
    if (text[i] >= 'A' && text[i] <= 'Z' || text[i] >= 'a' && text[i] <= 'z') {
      text[i] = tolower(text[i]);
    } else if (text[i] != '-') {
      text[i] = ' ';
    }
  }

  ss << text;

  while (ss >> input) {
    words.insert(input);
  }

  for (set<string>::iterator it = words.begin(); it != words.end(); it++)
    cout << *it << endl;

  return 0;
}
