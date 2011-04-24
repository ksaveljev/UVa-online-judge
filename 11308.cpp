#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

bool theTruthIsOutThere(const pair<string,int> &a, const pair<string,int> &b) {
  return a.second == b.second ? a.first < b.first : a.second < b.second;
}

int main(void) {
  int t;
  int m, n, b;
  int cost;
  int k;
  int amount;
  map<string,int> ingredients;
  string ingredient;
  string binder_name;
  string recipy_name;
  vector< pair<string,int> > result;

  cin >> t;

  while (t--) {
    result.clear();
    ingredients.clear();

    cin.ignore(100, '\n');
    getline(cin, binder_name);
    cin >> m >> n >> b;

    for (int i = 0; i < m; i++) {
      cin >> ingredient >> cost;
      ingredients[ingredient] = cost;
    }

    for (int i = 0; i < n; i++) {
      cin.ignore(100, '\n');
      getline(cin, recipy_name);
      cin >> k;

      cost = 0;
      for (int j = 0; j < k; j++) {
        cin >> ingredient >> amount;
        cost += ingredients[ingredient] * amount;
      }

      if (cost <= b) {
        result.push_back(make_pair(recipy_name, cost));
      }
    }
    
    sort(result.begin(), result.end(), theTruthIsOutThere);
    transform(binder_name.begin(), binder_name.end(), binder_name.begin(), ::toupper);

    cout << binder_name << endl;
    for (int i = 0, sz = result.size(); i < sz; i++) {
      cout << result[i].first << endl;
    }

    if (result.size() == 0) {
      cout << "Too expensive!" << endl;
    }

    cout << endl;
  }

  return 0;
}
