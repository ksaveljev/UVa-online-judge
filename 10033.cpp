#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
  int r[11];
  int ram[1001];
  int cases;
  int instruction;
  int count;

  cin >> cases;
  cin.ignore(100, '\n');
  cin.ignore(100, '\n');

  while (cases--) {
    count = 0;
    fill(r, r+11, 0);
    fill(ram, ram+1001, 0);

    while (cin.peek() != '\n' && cin.peek() != -1) {
      cin >> instruction;
      cin.ignore(100, '\n');
      
      ram[count] = instruction;
      count++;
    }

    cin.ignore(100, '\n');

    int pos = 0;
    int command;
    int result = 0;
    int d, n;
    while (true) {
      command = ram[pos];
      result++;

      if (command == 100) {
        break;
      }

      d = (command % 100) / 10;
      n = command % 10;

      switch (command/100) {
        case 0:
          if (r[n] > 0)
            pos = r[d];
          else
            pos++;
          break;
        case 2:
          r[d] = n;
          pos++;
          break;
        case 3:
          r[d] += n;
          r[d] %= 1000;
          pos++;
          break;
        case 4:
          r[d] *= n;
          r[d] %= 1000;
          pos++;
          break;
        case 5:
          r[d] = r[n];
          pos++;
          break;
        case 6:
          r[d] += r[n];
          r[d] %= 1000;
          pos++;
          break;
        case 7:
          r[d] *= r[n];
          r[d] %= 1000;
          pos++;
          break;
        case 8:
          r[d] = ram[r[n]];
          pos++;
          break;
        case 9:
          ram[r[n]] = r[d];
          pos++;
          break;
      }
    }

    cout << result << endl;
    
    if (cases)
      cout << endl;
  }

  return 0;
}
