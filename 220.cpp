#include <iostream>
#include <vector>
using namespace std;

char board[10][10];

void clear_board() {
  for (int row = 0; row < 10; row++)
    for (int column = 0; column < 10; column++)
      board[row][column] = '-';
}

void read_board() {
  for (int row = 1; row < 9; row++)
    for (int column = 1; column < 9; column++)
      cin >> board[row][column];
}

void print_board() {
  for (int row = 1; row < 9; row++) {
    for (int column = 1; column < 9; column++) {
      cout << board[row][column];
    }
    cout << endl;
  }
}

vector< pair<int,int> > get_legal_moves(char current_player) {
  int i, j;
  vector< pair<int,int> > legal_moves;
  char opposite_player = (current_player == 'B' ? 'W' : 'B');

  for (int row = 1; row < 9; row++) {
    for (int column = 1; column < 9; column++) {
      if (board[row][column] != '-') continue;

      if (board[row-1][column] == opposite_player) {
        for (i = row-1; i >= 1 && board[i][column] == opposite_player; i--);
        if (board[i][column] == current_player && i >= 1) {
          legal_moves.push_back(make_pair(row, column));
          continue;
        }
      }

      if (board[row+1][column] == opposite_player) {
        for (i = row+1; i < 9 && board[i][column] == opposite_player; i++);
        if (board[i][column] == current_player && i < 9) {
          legal_moves.push_back(make_pair(row, column));
          continue;
        }
      }

      if (board[row][column-1] == opposite_player) {
        for (i = column-1; i >= 1 && board[row][i] == opposite_player; i--);
        if (board[row][i] == current_player && i >= 1) {
          legal_moves.push_back(make_pair(row, column));
          continue;
        }
      }

      if (board[row][column+1] == opposite_player) {
        for (i = column+1; i < 9 && board[row][i] == opposite_player; i++);
        if (board[row][i] == current_player && i < 9) {
          legal_moves.push_back(make_pair(row, column));
          continue;
        }
      }

      if (board[row-1][column-1] == opposite_player) {
        for (i = row-1, j = column-1; i >= 1 && j >= 1 && board[i][j] == opposite_player; i--, j--);
        if (board[i][j] == current_player && i >= 1 && j >= 1) {
          legal_moves.push_back(make_pair(row, column));
          continue;
        }
      }

      if (board[row-1][column+1] == opposite_player) {
        for (i = row-1, j = column+1; i >= 1 && j < 9 && board[i][j] == opposite_player; i--, j++);
        if (board[i][j] == current_player && i >= 1 && j < 9) {
          legal_moves.push_back(make_pair(row, column));
          continue;
        }
      }

      if (board[row+1][column-1] == opposite_player) {
        for (i = row+1, j = column-1; i < 9 && j >= 1 && board[i][j] == opposite_player; i++, j--);
        if (board[i][j] == current_player && i < 9 && j >= 1) {
          legal_moves.push_back(make_pair(row, column));
          continue;
        }
      }

      if (board[row+1][column+1] == opposite_player) {
        for (i = row+1, j = column+1; i < 9 && j < 9 && board[i][j] == opposite_player; i++, j++);
        if (board[i][j] == current_player && i < 9 && j < 9) {
          legal_moves.push_back(make_pair(row, column));
          continue;
        }
      }
    }
  }

  return legal_moves;
}

char make_move(char current_player, int row, int column) {
  int i, j;
  vector< pair<int,int> > legal_moves = get_legal_moves(current_player);

  if (legal_moves.empty()) {
    current_player = (current_player == 'B' ? 'W' : 'B');
  }

  board[row][column] = current_player;
  char opposite_player = (current_player == 'B' ? 'W' : 'B');

  for (i = row-1; i >= 1 && board[i][column] == opposite_player; i--);
  if (board[i][column] == current_player && i >= 1)
    for (i = row-1; i >= 1 && board[i][column] == opposite_player; board[i][column] = current_player, i--);

  for (i = row+1; i < 9 && board[i][column] == opposite_player; i++);
  if (board[i][column] == current_player && i < 9)
    for (i = row+1; i < 9 && board[i][column] == opposite_player; board[i][column] = current_player, i++);

  for (i = column-1; i >= 1 && board[row][i] == opposite_player; i--);
  if (board[row][i] == current_player && i >= 1)
    for (i = column-1; i >= 1 && board[row][i] == opposite_player; board[row][i] = current_player, i--);

  for (i = column+1; i < 9 && board[row][i] == opposite_player; i++);
  if (board[row][i] == current_player && i < 9)
    for (i = column+1; i < 9 && board[row][i] == opposite_player; board[row][i] = current_player, i++);

  for (i = row-1, j = column-1; i >= 1 && j >= 1 && board[i][j] == opposite_player; i--, j--);
  if (board[i][j] == current_player && i >= 1 && j >= 1)
    for (i = row-1, j = column-1; i >= 1 && j >= 1 && board[i][j] == opposite_player; board[i][j] = current_player, i--, j--);

  for (i = row-1, j = column+1; i >= 1 && j < 9 && board[i][j] == opposite_player; i--, j++);
  if (board[i][j] == current_player && i >= 1 && j < 9)
    for (i = row-1, j = column+1; i >= 1 && j < 9 && board[i][j] == opposite_player; board[i][j] = current_player, i--, j++);

  for (i = row+1, j = column-1; i < 9 && j >= 1 && board[i][j] == opposite_player; i++, j--);
  if (board[i][j] == current_player && i < 9 && j >= 1)
    for (i = row+1, j = column-1; i < 9 && j >= 1 && board[i][j] == opposite_player; board[i][j] = current_player, i++, j--);

  for (i = row+1, j = column+1; i < 9 && j < 9 && board[i][j] == opposite_player; i++, j++);
  if (board[i][j] == current_player && i < 9 && j < 9)
    for (i = row+1, j = column+1; i < 9 && j < 9 && board[i][j] == opposite_player; board[i][j] = current_player, i++, j++);

  int black_count = 0;
  int white_count = 0;

  for (int row = 1; row < 9; row++) {
    for (int column = 1; column < 9; column++) {
      if (board[row][column] == 'B') black_count++;
      else if (board[row][column] == 'W') white_count++;
    }
  }

  cout << "Black - " << (black_count < 10 ? " " : "") << black_count << " White - " << (white_count < 10 ? " " : "") << white_count << endl;

  current_player = (current_player == 'B' ? 'W' : 'B');
  return current_player;
}

void print_legal_moves(char current_player) {
  vector< pair<int,int> > legal_moves = get_legal_moves(current_player);

  if (legal_moves.empty()) {
    cout << "No legal move." << endl;
    return;
  }

  for (int i = 0, sz = legal_moves.size(); i < sz; i++) {
    if (i > 0) cout << " ";
    cout << "(" << legal_moves[i].first << "," << legal_moves[i].second << ")";
  }
  cout << endl;
}

int main(void) {
  int number_of_games;
  char row, column;
  char command;
  char current_player;

  cin >> number_of_games;

  while (number_of_games--) {
    clear_board();
    read_board();

    cin >> current_player;

    bool end_of_game = false;
    while (!end_of_game) {
      cin >> command;

      switch (command) {
        case 'L':
          print_legal_moves(current_player);
          break;
        case 'M':
          cin >> row >> column;
          current_player = make_move(current_player, row - '0', column - '0');
          break;
        case 'Q':
          end_of_game = true;
          print_board();
          break;
      }
    }

    if (number_of_games)
      cout << endl;
  }

  return 0;
}
