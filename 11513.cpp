#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <sstream>
using namespace std;

int nums[9];
map<string,bool> visited;
map<string,string> result;

void precalculate() {
  pair<string,string> tmp;
  queue< pair<string,string> > q;

  tmp.first = "123456789";
  tmp.second = "";
  visited[tmp.first] = true;

  q.push(tmp);

  while (!q.empty()) {
    tmp = q.front();
    q.pop();

    result[tmp.first] = tmp.second;

    for (int i = 0; i < 3; i++) {
      swap(tmp.first[3+i], tmp.first[6+i]);
      swap(tmp.first[0+i], tmp.first[3+i]);

      if (visited.find(tmp.first) == visited.end()) {
        visited[tmp.first] = true;
        q.push(make_pair(tmp.first, (string("V") + (i == 0 ? "1" : i == 1 ? "2" : "3")) + tmp.second));
      }

      swap(tmp.first[0+i], tmp.first[3+i]);
      swap(tmp.first[3+i], tmp.first[6+i]);
    }

    for (int i = 0; i < 3; i++) {
      swap(tmp.first[3*i+0], tmp.first[3*i+1]);
      swap(tmp.first[3*i+1], tmp.first[3*i+2]);

      if (visited.find(tmp.first) == visited.end()) {
        visited[tmp.first] = true;
        q.push(make_pair(tmp.first, string("H") + (i == 0 ? "1" : i == 1 ? "2" : "3") + tmp.second));
      }

      swap(tmp.first[3*i+1], tmp.first[3*i+2]);
      swap(tmp.first[3*i+0], tmp.first[3*i+1]);
    }
  }
}

int main(void) {
  stringstream ss;

  precalculate();

  while (cin >> nums[0]) {
    if (nums[0] == 0)
      break;

    for (int i = 1; i < 9; i++)
      cin >> nums[i];

    for (int i = 0; i < 9; i++)
      ss << nums[i];

    string tmp = ss.str();
    ss.str("");
    ss.clear();

    if (result.find(tmp) == result.end())
      cout << "Not solvable" << endl;
    else
      cout << result[tmp].size() / 2 << " " << result[tmp] << endl;
  }

  return 0;
}
