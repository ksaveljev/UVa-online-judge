#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;

char maze[13][13];

vector<char> bfs(const pair<int,int> &start, const pair<int,int> &end) {
  pair< pair<int,int>, vector<char> > tmp;
  queue< pair< pair<int,int>, vector<char> > > q;

  tmp.first = start;
  vector<char> v;
  tmp.second = v;
  
  q.push(tmp);

  map<int,bool> visited;
  visited[start.first * 10000 + start.second] = true;

  while (!q.empty()) {
    tmp = q.front();
    q.pop();

    if (tmp.first == end) {
      return tmp.second;
    }

    pair<int,int> pos = tmp.first;

    if (pos.first > 2 && !visited[(pos.first-2)*10000 + pos.second] && maze[pos.first-1][pos.second] == ' ') {
      visited[(pos.first-2)*10000 + pos.second] = true;
      vector<char> v = tmp.second;
      v.push_back('N');
      q.push(make_pair(make_pair(pos.first-2, pos.second), v));
    }

    if (pos.second > 2 && !visited[pos.first * 10000 + pos.second - 2] && maze[pos.first][pos.second-1] == ' ') {
      visited[pos.first*10000 + pos.second-2] = true;
      vector<char> v = tmp.second;
      v.push_back('W');
      q.push(make_pair(make_pair(pos.first, pos.second-2), v));
    }

    if (pos.first < 11 && !visited[(pos.first+2)*10000 + pos.second] && maze[pos.first+1][pos.second] == ' ') {
      visited[(pos.first+2)*10000 + pos.second] = true;
      vector<char> v = tmp.second;
      v.push_back('S');
      q.push(make_pair(make_pair(pos.first+2, pos.second), v));
    }

    if (pos.second < 11 && !visited[pos.first*10000 + pos.second+2] && maze[pos.first][pos.second+1] == ' ') {
      visited[pos.first*10000 + pos.second+2] = true;
      vector<char> v = tmp.second;
      v.push_back('E');
      q.push(make_pair(make_pair(pos.first, pos.second+2), v));
    }
  }
}

int main(void) {
  pair<int,int> start, end;
  pair<int,int> wallstart, wallend;

  while (cin >> start.second >> start.first) {
    if (start.first == 0 && start.second == 0)
      break;

    cin >> end.second >> end.first;

    start.second = (start.second - 1) * 2 + 1;
    start.first = (start.first - 1) * 2 + 1;
    end.second = (end.second - 1) * 2 + 1;
    end.first = (end.first - 1) * 2 + 1;

    for (int i = 0; i < 13; i++)
      for (int j = 0; j < 13; j++)
        maze[i][j] = ' ';

    for (int i = 0; i < 3; i++) {
      cin >> wallstart.second >> wallstart.first >> wallend.second >> wallend.first;

      for (int a = wallstart.first * 2; a <= wallend.first * 2; a++) {
        for (int b = wallstart.second * 2; b <= wallend.second * 2; b++) {
          maze[a][b] = '*';
        }
      }
    }

    vector<char> result = bfs(start, end);

    for (int i = 0, sz = result.size(); i < sz; i++)
      cout << result[i];
    cout << endl;
  }

  return 0;
}
