#include <iostream>
#include <map>
using namespace std;

void rotate(bool sq[][50], int b)
{
  bool** tmp;

  tmp = new bool*[b];
  for (int i = 0; i < b; i++) {
    tmp[i] = new bool[b];
  }

  for (int i = 0; i < b; i++) {
    for (int j = 0; j < b; j++) {
      tmp[i][j] = sq[i][j];
    }
  }

  for (int i = 0; i < b; i++) {
    for (int j = b-1; j >= 0; j--) {
      sq[i][b-j-1] = tmp[j][i];
    }
  }

  for (int i = 0; i < b; i++) {
    delete [] tmp[i];
  }
  delete [] tmp;
}

unsigned int jenkins_one_at_a_time_hash(bool sq[][50], int n)
{
  unsigned int hash = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      hash += (sq[i][j] == true ? '1' : '0');
      hash += (hash << 10);
      hash ^= (hash >> 6);
    }
  }

  hash += (hash << 3);
  hash ^= (hash >> 11);
  hash += (hash << 15);

  return hash;
}

int main(void)
{
  int n, a, b;
  char c;
  int player, counter;
  bool field[50][50];
  unsigned int hash;
  map<unsigned int, bool> visited;

  while (cin >> n) {
    if (!n)
      break;

    visited.clear();
    player = 1;
    counter = 0;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        field[i][j] = false;
      }
    }

    visited.insert(make_pair(jenkins_one_at_a_time_hash(field, n), true));

    pair<int,int> winner;
    winner.first = -1;
    for (int i = 0; i < 2*n; i++) {
      cin >> a >> b >> c;

      counter++;

      if (winner.first > 0)
          continue;

      field[a-1][b-1] = (field[a-1][b-1] ? false : true);

      for (int j = 0; j < 4; j++) {
        rotate(field, n);
        hash = jenkins_one_at_a_time_hash(field, n);
        if (visited.find(hash) != visited.end()) {
          winner.first = (player == 1 ? 2 : 1);
          winner.second = counter;
        }
      }

      visited.insert(make_pair(hash, true));

      player = (player == 1 ? 2 : 1);
    }

    switch (winner.first) {
      case -1:
        cout << "Draw" << endl;
        break;
      case 1:
      case 2:
        cout << "Player " << winner.first << " wins on move " << winner.second << endl;
        break;
    }
  }

  return 0;
}
