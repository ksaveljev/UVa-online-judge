#include <iostream>
#include <string>
using namespace std;

int char2int(char c) {
  if (c == '_') {
    return 0;
  } else if (c == '.')
    return 27;

  return int(c - 'a' + 1);
}

char int2char(int c) {
  if (c == 0) {
    return '_';
  } else if (c == 27)
    return '.';

  return char(c + 'a' - 1);
}

void decode(string &input, int k) {
  int sz = input.size();
  int plaincode[sz];

  for (int i = 0; i < sz; i++) {
    plaincode[(k * i) % sz] = (char2int(input[i]) + i) % 28;
  }

  for (int i = 0; i < sz; i++) {
    cout << int2char(plaincode[i]);
  }

  cout << endl;
}

int main(void)
{
  int k;
  string input;

  while (cin >> k) {
    if (k == 0) {
      break;
    }

    // reading space after k
    cin.get();

    getline(cin, input);

    decode(input, k);
  }
  
  return 0;
}
