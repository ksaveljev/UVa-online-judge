#include <iostream>
#include <stack>
using namespace std;

bool compareOperator(char a, char b) {
  return (a == '*' || a == '/') >= (b == '*' || b == '/');
}

int main(void) {
  int n;
  char c;
  stack<char> s;

  cin >> n;
  cin.ignore(100, '\n');

  while (n--) {
    cin.ignore(100, '\n');

    while (cin.peek() != '\n' && cin.peek() != -1) {
      cin >> c;
      cin.ignore(100, '\n');

      if (c == '+' || c == '-' || c == '*' || c == '/') {
        if (s.empty()) {
          s.push(c);
        } else {
          while (!s.empty() && s.top() != '(') {
            if (compareOperator(s.top(), c)) {
              cout << s.top();
              s.pop();
            } else {
              break;
            }
          }
          s.push(c);
        }
      } else if (c == '(') {
        s.push(c);
      } else if (c == ')') {
        while (s.top() != '(') {
          cout << s.top();
          s.pop();
        }
        s.pop(); // pop '('
      } else { // operand
        cout << c;
      }
    }

    while (!s.empty()) {
      cout << s.top();
      s.pop();
    }

    cout << endl;

    if (n)
      cout << endl;
  }
}
