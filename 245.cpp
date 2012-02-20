#include <iostream>
#include <string>
#include <list>
#include <algorithm>
using namespace std;

// the original uncompressed file has no digit characters
// so we can safely assume that the word we read from the
// compressed file is a number by its first character
bool is_number(const string &s) {
  if (s[0] >= '0' && s[0] <= '9') {
    return true;
  }

  return false;
}

int string2int(const string &s) {
  int result = 0;

  for (int i = 0, sz = s.size(); i < sz; i++) {
    result = result * 10 + (s[i] - '0');
  }

  return result;
}

void process_current_word(string& current_word, list<string> &words, char c) {
  list<string>::iterator it;

  if (current_word.empty()) {
    cout << c;
  } else {
    if (is_number(current_word)) {
      int pos = string2int(current_word);
      it = words.begin();
      advance(it, pos - 1);

      cout << *it;
      current_word = *it;
      words.erase(it);

      words.push_front(current_word);
    } else {
      cout << current_word;
      words.push_front(current_word);
    }

    cout << c;
    current_word = "";
  }
}

int main(void)
{
  string input, current_word;
  list<string> words;
  list<string>::iterator it;

  while (getline(cin, input)) {
    if (input == "0") {
      break;
    }

    current_word = "";

    for (int i = 0, sz = input.size(); i < sz; i++) {
      if (input[i] >= 'a' && input[i] <= 'z' || input[i] >= 'A' && input[i] <= 'Z' || input[i] >= '0' && input[i] <= '9') {
        current_word += input[i];
      } else {
        process_current_word(current_word, words, input[i]);
      }
    }

    process_current_word(current_word, words, '\n');
  }

  return 0;
}
