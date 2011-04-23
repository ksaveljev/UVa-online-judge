#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(void) {
  string text = "";
  string input;
  int counts[40];
  int counter;

  for (int i = 0; i < 40; i++)
    counts[i] = 0;

  while (getline(cin, input)) {
    if (input[0] == '#') {
      for (int i = 0, sz = text.size(); i < sz; i++) {
        if (text[i] == '?' || text[i] == '!' || text[i] == ',' || text[i] == '.')
          text[i] = ' ';
      }

      stringstream ss;
      ss << text;

      while (ss >> input) {
        counter = 0;
        for (int i = 0, sz = input.size(); i < sz; i++) {
          if (input[i] >= 'A' && input[i] <= 'Z' || input[i] >= 'a' && input[i] <= 'z')
            counter++;
        }
        counts[counter]++;
      }

      for (int i = 1; i < 40; i++) {
        if (counts[i]) {
          cout << i << " " << counts[i] << endl;
        }
      }
      cout << endl;

      for (int i = 0; i < 40; i++)
        counts[i] = 0;

      text = "";
      continue;
    }

    if (input[input.size() - 1] == '-') {
      text += string(input.begin(), input.begin() + input.size() - 1);
    } else {
      input += " ";
      text += input;
    }
  }

  return 0;
}
