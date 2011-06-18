#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void) {
  char c;
  string input;
  int result;
  vector<int> score;

  while (getline(cin, input)) {
    if (input == "Game Over")
      break;

    result = 0;
    score.clear();

    for (int i = 0, sz = input.size(); i < sz; i++) {
      if (input[i] == ' ') continue;
      
      if (input[i] == 'X')
        score.push_back(10);
      else if (input[i] == '/')
        score.push_back(10 - score[score.size()-1]);
      else
        score.push_back(input[i] - '0');
    }

    int frames = 0;
    for (int i = 0, sz = score.size(); i < sz; i++) {
      if (frames == 10) break;

      if (score[i] == 10) {
        result += score[i] + score[i+1] + score[i+2];
        frames++;
      } else if (score[i] + score[i+1] == 10) {
        result += score[i] + score[i+1] + score[i+2];
        frames++;
        i++;
      } else {
        result += score[i] + score[i+1];
        frames++;
        i++;
      }
    }

    cout << result << endl;
  }

  return 0;
}
