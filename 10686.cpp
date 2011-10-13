#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

int main(void)
{
  int n, c, w, p;
  string category, keyword, input;

  cin >> n;

  while (n--) {
    cin >> c;

    vector<string> categories;
    map<string,int> needed, result;
    multimap<string,string> keywords;
    multimap<string,string>::iterator it;
    pair<multimap<string,string>::iterator,multimap<string,string>::iterator> ret;

    for (int i = 0; i < c; i++) {
      cin >> category >> w >> p;
      map<string,bool> visited;
      categories.push_back(category);
      needed[category] = p;
      for (int j = 0; j < w; j++) {
        cin >> keyword;
        if (visited.find(keyword) == visited.end()) {
          visited[keyword] = true;
          result[keyword] = 0;
          keywords.insert(make_pair(keyword, category));
        }
      }
    }
    
    cin.ignore(100, '\n');

    map<string,bool> visited;
    while (getline(cin, input)) {
      if (input == "") {
        break;
      }

      for (int i = 0, sz = input.size(); i < sz; i++) {
        if (input[i] >= 'a' && input[i] <= 'z' || input[i] >= 'A' && input[i] <= 'Z') {

        } else {
          input[i] = ' ';
        }
      }

      stringstream ss(input, stringstream::in);

      while (ss >> input) {
        if (visited.find(input) != visited.end()) {
          continue;
        }
        visited[input] = true;
        if (keywords.count(input) > 0) {
          ret = keywords.equal_range(input);
          for (it = ret.first; it != ret.second; it++) {
            result[it->second] += 1;
          }
        }
      }
    }

    bool first = true;
    for (int i = 0, sz = categories.size(); i < sz; i++) {
      if (result[categories[i]] >= needed[categories[i]]) {
        if (!first) {
          cout << ",";
        }

        cout << categories[i];
        first = false;
      }
    }

    if (first) {
      cout << "SQF Problem.";
    }

    cout << endl;
  }
  
  return 0;
}
