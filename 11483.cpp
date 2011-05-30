#include <iostream>
#include <string>
using namespace std;

int main(void) {
  int n;
  int counter = 0;
  string input;

  while (cin >> n) {
    if (!n)
      break;

    counter++;
    cout << "Case " << counter << ":" << endl;
    cout << "#include<string.h>" << endl;
    cout << "#include<stdio.h>" << endl;
    cout << "int main()" << endl;
    cout << "{" << endl;

    cin.ignore(100, '\n');

    for (int i = 0; i < n; i++) {
      getline(cin, input);
      cout << "printf(\"";
      for (int j = 0, sz = input.size(); j < sz; j++) {
        if (input[j] == '"' || input[j] == '\\') {
          cout << "\\";
        }
        cout << input[j];
      }
      cout << "\\n\");" << endl;
    }

    cout << "printf(\"\\n\");" << endl;
    cout << "return 0;" << endl;
    cout << "}" << endl;
  }

  return 0;
}
