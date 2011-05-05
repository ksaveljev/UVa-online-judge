#include <iostream>
#include <string>
using namespace std;

int n;
char field[101][101];

struct word {
  pair<int,int> start;
  pair<int,int> end;
};

word find_word(const string &s) {
  bool found;
  word result;
  int sz = s.size();

  result.start.first = -1;

  // left to right
  for (int i = 0; i < n; i++) {
    for (int j = 0; j + sz - 1 < n; j++) {
      
      found = true;
      for (int a = 0; a < sz; a++) {
        if (s[a] != field[i][j+a]) {
          found = false;
          break;
        }
      }
      if (found) {
        result.start.first = i + 1;
        result.start.second = j + 1;
        result.end.first = i + 1;
        result.end.second = j + sz;
        return result;
      }

    }
  }

  // right to left
  for (int i = 0; i < n; i++) {
    for (int j = n - 1; j - sz + 1 >= 0; j--) {

      found = true;
      for (int a = 0; a < sz; a++) {
        if (s[a] != field[i][j-a]) {
          found = false;
          break;
        }
      }
      if (found) {
        result.start.first = i + 1;
        result.start.second = j + 1;
        result.end.first = i + 1;
        result.end.second = j + 1 - sz + 1;
      }

    }
  }

  // top to bottom
  for (int j = 0; j < n; j++) {
    for (int i = 0; i + sz - 1 < n; i++) {
      
      found = true;
      for (int a = 0; a < sz; a++) {
        if (s[a] != field[i+a][j]) {
          found = false;
          break;
        }
      }
      if (found) {
        result.start.first = i + 1;
        result.start.second = j + 1;
        result.end.first = i + sz;
        result.end.second = j + 1;
      }

    }
  }

  // diagonal left to right
  for (int i = 0; i + sz - 1 < n; i++) {
    for (int j = 0; j + sz - 1 < n; j++) {

      found = true;
      for (int a = 0; a < sz; a++) {
        if (s[a] != field[i+a][j+a]) {
          found = false;
          break;
        }
      }
      if (found) {
        result.start.first = i + 1;
        result.start.second = j + 1;
        result.end.first = i + sz;
        result.end.second = j + sz;
      }

    }
  }

  // diagonal right to left
  for (int i = 0; i + sz - 1 < n; i++) {
    for (int j = n - 1; j - sz + 1 >= 0; j--) {

      found = true;
      for (int a = 0; a < sz; a++) {
        if (s[a] != field[i+a][j-a]) {
          found = false;
          break;
        }
      }
      if (found) {
        result.start.first = i + 1;
        result.start.second = j + 1;
        result.end.first = i + sz;
        result.end.second = j + 1 - sz + 1;
      }

    }
  }

  return result;
}

int main(void) {
  word result;
  string input;

  cin >> n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> field[i][j];
    }
  }

  cin.ignore(100, '\n');

  while (getline(cin, input)) {
    if (input == "0")
      break;

    result = find_word(input);

    if (result.start.first == -1)
      cout << "Not found" << endl;
    else
      cout << result.start.first << "," << result.start.second << " " << result.end.first << "," << result.end.second << endl;
  }

  return 0;
}
