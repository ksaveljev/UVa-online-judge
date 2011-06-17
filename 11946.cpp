#include <iostream>
#include <string>
using namespace std;

int main(void) {
  int t;
  size_t pos;
  string input;

  string encoded = "48CD3F6H1JKLMN09QR57UVWXY2 ,.";
  string decoded = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ,.";

  cin >> t;
  cin.ignore(100, '\n');

  while (getline(cin, input)) {
    for (int i = 0, sz = input.size(); i < sz; i++) {
      cout << decoded[int(encoded.find(input[i]))];
    }
    cout << endl;
  }
  
  return 0;
}
