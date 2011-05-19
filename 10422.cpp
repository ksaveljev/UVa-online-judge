#include <iostream>
#include <queue>
#include <string>
#include <map>
using namespace std;

struct pos {
  int i;
  int j;
};

int solve(const string &end) {
  map<string,bool> visited;
  pair<string,int> tmp;
  queue< pair<string,int> > q;
  pos empty;

  string start = "111110111100 110000100000";
  string s;

  tmp.first = start;
  tmp.second = 0;

  q.push(tmp);

  while (!q.empty()) {
    tmp = q.front();
    q.pop();

    if (tmp.first == end)
      return tmp.second;

    if (tmp.second == 10)
      continue;

    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
        if (tmp.first[i*5+j] == ' ') {
          empty.i = i;
          empty.j = j;
          i = 5;
          break;
        }
      }
    }

    if (empty.i - 2 >= 0 && empty.j - 1 >= 0) {
      s = tmp.first;
      s[empty.i*5 + empty.j] = s[(empty.i-2)*5 + empty.j-1];
      s[(empty.i-2)*5 + empty.j-1] = ' ';
      if (visited.find(s) == visited.end()) {
        q.push(make_pair(s, tmp.second+1));
        visited[s] = true;
      }
    }

    if (empty.i - 2 >= 0 && empty.j + 1 < 5) {
      s = tmp.first;
      s[empty.i*5 + empty.j] = s[(empty.i-2)*5 + empty.j+1];
      s[(empty.i-2)*5 + empty.j+1] = ' ';
      if (visited.find(s) == visited.end()) {
        q.push(make_pair(s, tmp.second+1));
        visited[s] = true;
      }
    }

    if (empty.i - 1 >= 0 && empty.j - 2 >= 0) {
      s = tmp.first;
      s[empty.i*5 + empty.j] = s[(empty.i-1)*5 + empty.j-2];
      s[(empty.i-1)*5 + empty.j-2] = ' ';
      if (visited.find(s) == visited.end()) {
        q.push(make_pair(s, tmp.second+1));
        visited[s] = true;
      }
    }

    if (empty.i - 1 >= 0 && empty.j + 2 < 5) {
      s = tmp.first;
      s[empty.i*5 + empty.j] = s[(empty.i-1)*5 + empty.j+2];
      s[(empty.i-1)*5 + empty.j+2] = ' ';
      if (visited.find(s) == visited.end()) {
        q.push(make_pair(s, tmp.second+1));
        visited[s] = true;
      }
    }

    if (empty.i + 1 < 5 && empty.j - 2 >= 0) {
      s = tmp.first;
      s[empty.i*5 + empty.j] = s[(empty.i+1)*5 + empty.j-2];
      s[(empty.i+1)*5 + empty.j-2] = ' ';
      if (visited.find(s) == visited.end()) {
        q.push(make_pair(s, tmp.second+1));
        visited[s] = true;
      }
    }

    if (empty.i + 1 < 5 && empty.j + 2 < 5) {
      s = tmp.first;
      s[empty.i*5 + empty.j] = s[(empty.i+1)*5 + empty.j+2];
      s[(empty.i+1)*5 + empty.j+2] = ' ';
      if (visited.find(s) == visited.end()) {
        q.push(make_pair(s, tmp.second+1));
        visited[s] = true;
      }
    }

    if (empty.i + 2 < 5 && empty.j - 1 >= 0) {
      s = tmp.first;
      s[empty.i*5 + empty.j] = s[(empty.i+2)*5 + empty.j-1];
      s[(empty.i+2)*5 + empty.j-1] = ' ';
      if (visited.find(s) == visited.end()) {
        q.push(make_pair(s, tmp.second+1));
        visited[s] = true;
      }
    } 

    if (empty.i + 2 < 5 && empty.j + 1 < 5) {
      s = tmp.first;
      s[empty.i*5 + empty.j] = s[(empty.i+2)*5 + empty.j+1];
      s[(empty.i+2)*5 + empty.j+1] = ' ';
      if (visited.find(s) == visited.end()) {
        q.push(make_pair(s, tmp.second+1));
        visited[s] = true;
      }
    }
  }

  return -1;
}

int main(void) {
  int t;
  string input, board = "";

  cin >> t;
  cin.ignore(100, '\n');

  while (t--) {
    board = "";

    for (int i = 0; i < 5; i++) {
      getline(cin, input);
      board += input;
    }

    int result = solve(board);

    if (result == -1)
      cout << "Unsolvable in less than 11 move(s)." << endl;
    else
      cout << "Solvable in " << result << " move(s)." << endl;
  }

  return 0;
}
