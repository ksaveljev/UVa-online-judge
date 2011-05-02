#include <iostream>
#include <queue>
#include <map>
using namespace std;

struct domino {
  bool knocked;
  int id;
};

domino dominos[10001];

queue<domino> q;
multimap<int,int> mmap;
multimap<int,int>::iterator it;
pair<multimap<int,int>::iterator,multimap<int,int>::iterator> ret;

void knock_em_down() {
  domino tmp;

  while (!q.empty()) {
    tmp = q.front();
    q.pop();

    ret = mmap.equal_range(tmp.id);
    for (it = ret.first; it != ret.second; it++) {
      if (!dominos[(*it).second].knocked) {
        dominos[(*it).second].knocked = true;
        q.push(dominos[(*it).second]);
      }
    }
  }
}

int main(void) {
  int cases;
  int n, m, l;
  int d1, d2;
  domino tmp;

  cin >> cases;

  while (cases--) {
    cin >> n >> m >> l;

    mmap.clear();
    
    for (int i = 0; i < 10000; i++) {
      dominos[i].id = i;
      dominos[i].knocked = false;
    }

    for (int i = 0; i < m; i++) {
      cin >> d1 >> d2;
      mmap.insert(make_pair(d1, d2));
    }

    for (int i = 0; i < l; i++) {
      cin >> tmp.id;
      dominos[tmp.id].knocked = true;
      q.push(tmp);
    }

    knock_em_down();

    int result = 0;
    for (int i = 1; i <= n; i++)
      if (dominos[i].knocked)
        result++;

    cout << result << endl;
  }

  return 0;
}
