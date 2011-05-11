#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
  string input;
  vector<string> result;
  multimap<string,string> m;
  multimap<string,string>::iterator it;
  pair<multimap<string,string>::iterator, multimap<string,string>::iterator> ret;

  while (getline(cin, input)) {
    if (input == "XXXXXX")
      break;

    string tmp = string(input.begin(), input.end());
    sort(tmp.begin(), tmp.end(), less<char>());

    m.insert(make_pair(tmp, input));
  }

  while (getline(cin, input)) {
    if (input == "XXXXXX")
      break;

    sort(input.begin(), input.end(), less<char>());

    ret = m.equal_range(input);
    for (it = ret.first; it != ret.second; it++) {
      result.push_back(it->second);
    }

    sort(result.begin(), result.end());

    for (int i = 0, sz = result.size(); i < sz; i++)
      cout << result[i] << endl;

    if (result.size() == 0) {
      cout << "NOT A VALID WORD" << endl;
    }

    result.clear();

    cout << "******" << endl;
  }

  return 0;
}
