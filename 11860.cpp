#include <iostream>
#include <string>
#include <map>
#include <sstream>
using namespace std;

int main(void)
{
  int t;
  int* words = new int[100001];
  map<string,int> m;
  string input;
  int wordsnum, counter;

  cin >> t;

  for (int case_num = 0; case_num < t; case_num++) {
    m.clear();
    counter = 0;
    wordsnum = 0;

    while (getline(cin, input)) {
      if (input == "END") {
        break;
      }

      for (int i = 0, sz = input.size(); i < sz; i++) {
        if (input[i] < 'a' || input[i] > 'z') {
          input[i] = ' ';
        }
      }

      stringstream ss(input, stringstream::in);
      while (ss >> input) {
        if (m.find(input) == m.end()) {
          m[input] = counter;
          words[wordsnum] = counter;
          counter++;
          wordsnum++;
        } else {
          words[wordsnum] = m[input];
          wordsnum++;
        }
      }
    }

    int a = 0, b = 0;
    int haswords = 0;
    map<int,int> current;
    pair<int,int> result = make_pair(-1,-1);

    current[words[0]] = 1;
    haswords++;

    if (wordsnum == 1) {
      result = make_pair(0, 0);
    }

    while (true) {
      if (a == wordsnum - 1 && b == wordsnum - 1) {
        break;
      }

      if (haswords == counter) {
        if (result.first == -1) {
          result = make_pair(a, b);
        } else {
          if (b - a < result.second - result.first) {
            result = make_pair(a, b);
          }
        }

        if (current[words[a]] > 1) {
          current[words[a]] -= 1;
          a += 1;
        } else {
          current[words[a]] = 0;
          a += 1;
          haswords--;
        }
      } else {
        if (b == wordsnum - 1) {
          break;
        }

        if (current.find(words[b+1]) == current.end() || current[words[b+1]] == 0) {
          current[words[b+1]] = 1;
          b += 1;
          haswords++;
        } else {
          current[words[b+1]] += 1;
          b += 1;
        }
      }
    }

    cout << "Document " << case_num + 1 << ": " << result.first + 1 << " " << result.second + 1 << endl;
  }



  delete [] words;

  return 0;
}
