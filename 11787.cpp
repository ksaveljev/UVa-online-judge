#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

string hieroglyphs = "BUSPFTM";

int hieroglyph_to_int(string &input) {
  int result = 0, pos;

  for (int i = 0, sz = input.size(); i < sz; i++) {
    pos = hieroglyphs.find(input[i]);
    result += pow(10, pos);
  }

  return result;
}

bool is_ordered(string &input) {
  char prev = input[0];
  int diff = 0, cur_pos, prev_pos = hieroglyphs.find(prev);

  for (int i = 1, sz = input.size(); i < sz; i++) {
    cur_pos = hieroglyphs.find(input[i]);
    if (cur_pos - prev_pos == 0) {
      continue;
    }

    if (diff == 0) {
      diff = cur_pos - prev_pos;
      prev_pos = cur_pos;
      continue;
    }

    if (cur_pos - prev_pos > 0 && diff < 0 || cur_pos - prev_pos < 0 && diff > 0) {
      return false;
    }

    prev_pos = cur_pos;
  }

  return true;
}

bool no_more_than_nine_equal_chars(string &input) {
  char prev = input[0];
  int count = 1;

  for (int i = 1, sz = input.size(); i < sz; i++) {
    if (input[i] == prev) {
      count++;
    } else {
      if (count > 9) {
        return false;
      } else {
        prev = input[i];
        count = 1;
      }
    }
  }

  if (count > 9) {
    return false;
  }

  return true;
}

bool correct_hieroglyph(string &input) {
  return is_ordered(input) && no_more_than_nine_equal_chars(input);
}

int main(void)
{
  int n;
  string input;

  cin >> n;
  getline(cin, input); // \n after n

  while (n--) {
    getline(cin, input);

    if (!correct_hieroglyph(input)) {
      cout << "error" << endl;
      continue;
    }

    cout << hieroglyph_to_int(input) << endl;
  }
  
  return 0;
}
