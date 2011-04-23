#include <iostream>
#include <string>
#include <set>
using namespace std;

set<string> palindromes;

bool is_palindrome(const string &input, int start, int end) {
  string a(input.begin() + start, input.begin() + end);
  string b(a.rbegin(), a.rend());

  return a == b;
}

int count_palindromes(const string &input) {
  int counter = 0;

  for (int i = 0, sz = input.size(); i < sz; i++) {
    for (int j = i + 1; j <= sz; j++) {
      if (is_palindrome(input, i, j)) {
        palindromes.insert(string(input.begin() + i, input.begin() + j));
      }
    }
  }

  return palindromes.size();
}

int main(void) {
  string input;

  while (cin >> input) {
    palindromes.clear();
    cout << "The string '" << input << "' contains " << count_palindromes(input) << " palindromes." << endl;
  }

  return 0;
}
