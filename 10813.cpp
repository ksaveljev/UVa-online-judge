#include <iostream>
using namespace std;

int main(void) {
  int games;
  int nums[75];
  int card[5][5];

  cin >> games;

  while (games--) {
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
        if (i == 2 && j == 2) {
          card[i][j] = 0;
          continue;
        }

        cin >> card[i][j];
      }
    }

    for (int i = 0; i < 75; i++) {
      cin >> nums[i];
    }

    bool bingo = false;
    int result = 0;
    bool newentry = false;
    for (int i = 0; i < 75; i++) {
      for (int a = 0; a < 5; a++) {
        for (int b = 0; b < 5; b++) {
          if (card[a][b] == nums[i]) {
            card[a][b] = 0;
            newentry = true;
          }
        }
      }

      if (newentry) {
        for (int a = 0; a < 5; a++) {
          int sum = 0;
          for (int b = 0; b < 5; b++) {
            if (card[a][b] == 0)
              sum++;
          }

          if (sum == 5) {
            bingo = true;
            result = i + 1;
            break;
          }

          sum = 0;
          for (int b = 0; b < 5; b++) {
            if (card[b][a] == 0)
              sum++;
          }

          if (sum == 5) {
            bingo = true;
            result = i + 1;
            break;
          }
        }

        if (card[0][0] == 0 && card[1][1] == 0 && card[3][3] == 0 && card[4][4] == 0 || card[0][4] == 0 && card[1][3] == 0 && card[3][1] == 0 && card[4][0] == 0) {
          bingo = true;
          result = i + 1;
          break;
        }

        newentry = false;
      }

      if (bingo)
        break;
    }

    cout << "BINGO after " << result << " numbers announced" << endl;
  }

  return 0;
}
