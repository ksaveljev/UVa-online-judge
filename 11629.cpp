#include <iostream>
#include <string>
#include <map>
using namespace std;

int get_operation(char c1, char c2 = ' ') {
  if (c2 == ' ') {
    switch (c1) {
      case '<':
        return 1;
      case '>':
        return 2;
      case '=':
        return 3;
    }
  } else {
    if (c1 == '<' && c2 == '=') {
      return 4;
    } else if (c1 == '>' && c2 == '=') {
      return 5;
    }
  }
}

int main(void) {
  int p, g;
  char c1, c2;
  int operation;
  string input;
  map<string,int> m;
  int p1, p2;
  int n;

  cin >> p >> g;

  while (p--) {
    cin >> input >> p1 >> c1 >> p2;
    m[input] = p1*10 + p2;
  }

  for (int guess = 0; guess < g; guess++) {
    int sum = 0;

    while (cin >> input) {
      sum += m[input];

      cin >> c1;
      if (c1 == '+') {
        continue;
      }
      
      break;
    }

    if (cin.peek() != ' ') {
      cin >> c2;
      operation = get_operation(c1, c2);
    } else {
      operation = get_operation(c1);
    }

    cin >> n;
    n *= 10;

    bool correct = true;
    switch (operation) {
      case 1:
        correct = sum < n;
        break;
      case 2:
        correct = sum > n;
        break;
      case 3:
        correct = sum == n;
        break;
      case 4:
        correct = sum <= n;
        break;
      case 5:
        correct = sum >= n;
        break;
    }

    if (correct)
      cout << "Guess #" << guess+1 << " was correct." << endl;
    else
      cout << "Guess #" << guess+1 << " was incorrect." << endl;
  }

  return 0;
}
