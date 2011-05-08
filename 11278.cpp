#include <iostream>
#include <string>
using namespace std;

int main(void) {
  string qwerty = " `1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./~!@#$%^&*()_+QWERTYUIOP{}|ASDFGHJKL:\"ZXCVBNM<>?";
  string dvorak = " `123qjlmfp/[]456.orsuyb;=\\789aehtdck-0zx,inwvg'~!@#QJLMFP?{}$%^>ORSUYB:+|&*(AEHTDCK_)ZX<INWVG\"";
  string input;
  size_t pos;

  while (getline(cin, input)) {
    for (int i = 0, sz = input.size(); i < sz; i++) {
      pos = qwerty.find(input[i]);
      cout << dvorak[pos];
    }
    cout << endl;
  }

  return 0;
}
