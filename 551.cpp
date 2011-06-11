#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void) {
  string input;

  while (getline(cin, input)) {
    int pos = 1;
    stack<char> s;

    bool ok = true;
    for (int i = 0, sz = input.size(); i < sz; i++) {
      if (input[i] == '[' || input[i] == '{' || input[i] == '<') {
        s.push(input[i]);
      } else if (input[i] == '(') {
        if (i+1 == sz) {
          ok = false;
          break;
        }

        if (input[i+1] == '*') {
          s.push('a');
          i++;
        } else {
          s.push('(');
        }
      } else if (input[i] == '*') {
        if (i+1 == sz)
          continue;

        if (input[i+1] == ')') {
          if (s.empty() || s.top() != 'a') {
            ok = false;
            break;
          } else {
            s.pop();
            i++;
          }
        }
      } else if (input[i] == ')' || input[i] == ']' || input[i] == '}' || input[i] == '>') {
        if (s.empty()) {
          ok = false;
          break;
        }

        switch (input[i]) {
          case ')':
            if (s.top() != '(') {
              ok = false;
            } else {
              s.pop();
            }
            break;
          case ']':
            if (s.top() != '[') {
              ok = false;
            } else {
              s.pop();
            }
            break;
          case '}':
            if (s.top() != '{') {
              ok = false;
            } else {
              s.pop();
            }
            break;
          case '>':
            if (s.top() != '<') {
              ok = false;
            } else {
              s.pop();
            }
            break;
        }

        if (!ok)
          break;
      }

      pos++;
    }

    if (!s.empty())
      ok = false;

    if (ok) {
      cout << "YES" << endl;
    } else {
      cout << "NO " << pos << endl;
    }
  }

  return 0;
}
