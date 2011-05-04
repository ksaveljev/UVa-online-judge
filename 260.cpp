#include <iostream>
using namespace std;

int n;
char field[201][201];
bool visited[201][201];

bool dfs(int a, int b, char c) {
  if (a == n - 1)
    return true;

  if (a > 0 && b > 0 && !visited[a-1][b-1] && field[a-1][b-1] == c) {
    visited[a-1][b-1] = true;
    if (dfs(a-1, b-1, c))
      return true;
  }

  if (a > 0 && !visited[a-1][b] && field[a-1][b] == c) {
    visited[a-1][b] = true;
    if (dfs(a-1, b, c))
      return true;
  }

  if (b > 0 && !visited[a][b-1] && field[a][b-1] == c) {
    visited[a][b-1] = true;
    if (dfs(a, b-1, c))
      return true;
  }

  if (b < n - 1 && !visited[a][b+1] && field[a][b+1] == c) {
    visited[a][b+1] = true;
    if (dfs(a, b+1, c))
      return true;
  }

  if (a < n - 1 && !visited[a+1][b] && field[a+1][b] == c) {
    visited[a+1][b] = true;
    if (dfs(a+1, b, c))
      return true;
  }

  if (a < n - 1 && b < n - 1 && !visited[a+1][b+1] && field[a+1][b+1] == c) {
    visited[a+1][b+1] = true;
    if (dfs(a+1, b+1, c))
      return true;
  }

  return false;
}

int main(void) {
  bool won;
  int game_num = 0;

  while (cin >> n) {
    if (n == 0)
      break;

    game_num++;

    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        cin >> field[i][j];

    won = false;

    // check if black wins
    for (int i = 0; i < n; i++) {
      if (field[0][i] == 'b') {
        
        for (int a = 0; a < n; a++)
          for (int b = 0; b < n; b++)
            visited[a][b] = false;

        visited[0][i] = true;
        won = dfs(0, i, 'b');
        if (won)
          break;
      }
    }

    if (won)
      cout << game_num << " " << "B" << endl;
    else
      cout << game_num << " " << "W" << endl;
  }

  return 0;
}
