#include <iostream>
#include <string>
using namespace std;

int main(void) {
  int t;
  int result;
  string input;
  int keys[26] = {1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4};

  cin >> t;
  cin.ignore(100, '\n');

  for (int casenum = 0; casenum < t; casenum++) {
    getline(cin, input);

    result = 0;

    for (int i = 0, sz = input.size(); i < sz; i++) {
      if (input[i] == ' ')
        result++;
      else
        result += keys[int(input[i] - 'a')];
    }

    cout << "Case #" << casenum+1 << ": " << result << endl;
  }

  return 0;
}
