#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int decode[36] = {1,3,5,10,14,19,22,29,33,8,11,15,18,23,26,28,31,35,2,6,13,16,21,25,30,32,34,0,4,7,9,12,17,20,24,27};
char msg[110];

int main(void)
{
  string input;

  while (getline(cin, input)) {
    if (input.size() == 0) {
      cout << endl;
      continue;
    }

    for (int i = 0; i < input.size() / 36; i++) {
      for (int j = 0; j < 36; j++) {
        msg[i*36+j] = input[i * 36 + decode[j]];
      }
    }

    int count = 0;
    for (int i = 0; i < input.size(); i++) {
      if (msg[i] == '#') {
        count++;
      } else
        break;
    }

    string result = string(msg+count, msg+input.size());
    reverse(result.begin(), result.end());

    cout << result << endl;
  }
  
  return 0;
}

