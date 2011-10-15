#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(void)
{
  int case_num = 0;
  string input;
  map<string,string> lang;

  lang["HELLO"] = "ENGLISH";
  lang["HOLA"] = "SPANISH";
  lang["HALLO"] = "GERMAN";
  lang["BONJOUR"] = "FRENCH";
  lang["CIAO"] = "ITALIAN";
  lang["ZDRAVSTVUJTE"] = "RUSSIAN";

  while (getline(cin, input)) {
    if (input == "#") {
      break;
    }

    case_num++;

    cout << "Case " << case_num << ": ";

    if (lang.find(input) == lang.end()) {
      cout << "UNKNOWN" << endl;
    } else {
      cout << lang[input] << endl;
    }
  }
  
  return 0;
}
