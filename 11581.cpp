#include <iostream>
#include <map>
using namespace std;

int board_value(int board[3][3]) {
  int tmp = 0;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      tmp = tmp * 10 + board[i][j];
    }
  }

  return tmp;
}

void visit(int board[3][3], map<int,bool>& visited) {
  visited[board_value(board)] = true;
}

void mutate(int board[3][3]) {
  int tmp[3][3], sum;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      sum = 0;

      if (i > 0) {
        sum += board[i-1][j];
      }

      if (j > 0) {
        sum += board[i][j-1];
      }

      if (i < 2) {
        sum += board[i+1][j];
      }

      if (j < 2) {
        sum += board[i][j+1];
      }

      tmp[i][j] = sum % 2;
    }
  }

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      board[i][j] = tmp[i][j];
    }
  }
}

int main(void)
{
  int t, index, tmp;
  int board[3][3];
  map<int,bool> visited;

  cin >> t;

  while (t--) {
    index = -1;
    visited.clear();

    for (int i = 0; i < 3; i++) {
      cin >> tmp;
      for (int j = 2; j >= 0; j--) {
        board[i][j] = tmp % 10;
        tmp /= 10;
      }
    }

    visit(board, visited);
    index++;

    while (true) {
      mutate(board);

      if (visited.find(board_value(board)) == visited.end()) {
        visit(board, visited);
        index++;
      } else {
        cout << index - 1 << endl;
        break;
      }
    }
  }
  
  return 0;
}
