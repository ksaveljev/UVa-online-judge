#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(void) {
  int cases;
  string input;
  string plaintext, substitute;
  map<char,char> cypher;

  cin >> cases;
  cin.ignore(100, '\n');
  cin.ignore(100, '\n');

  while (cases--) {
    cypher.clear();

    getline(cin, plaintext);
    getline(cin, substitute);

    for (int i = 0, sz = plaintext.size(); i < sz; i++)
      cypher[plaintext[i]] = substitute[i];

    cout << substitute << endl;
    cout << plaintext << endl;

    while (getline(cin, input)) {
      if (input == "")
        break;

      for (int i = 0, sz = input.size(); i < sz; i++) {
        if (cypher.find(input[i]) == cypher.end())
          cout << input[i];
        else
          cout << cypher[input[i]];
      }
      cout << endl;
    }

    if (cases)
      cout << endl;
  }
}
