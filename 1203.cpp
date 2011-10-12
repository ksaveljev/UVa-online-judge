#include <iostream>
#include <queue>
#include <string>
#include <map>
using namespace std;

class theTruthIsOutThere
{
  public:
  bool operator() (const pair<int,int>& a, const pair<int,int>& b) {
    if (a.second == b.second) {
      return a.first > b.first;
    } else {
      return a.second > b.second;
    }
  }
};

int main(void)
{
  int qnum, period, k;
  string cmd;
  map<int,int> periods;
  priority_queue< pair<int,int>, vector< pair<int,int> >, theTruthIsOutThere > queue;

  while (cin >> cmd) {
    if (cmd == "#") {
      break;
    }

    cin >> qnum >> period;
    periods[qnum] = period;
    queue.push(make_pair(qnum, period));
  }

  cin >> k;

  while (k--) {
    pair<int,int> tmp = queue.top();
    queue.pop();

    cout << tmp.first << endl;

    tmp.second += periods[tmp.first];
    queue.push(tmp);
  }
  
  return 0;
}
