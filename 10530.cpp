#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main(void) {
  int num;
  string answer[2];
  bool verify[11];

  memset(verify, true, sizeof verify);

  while (cin >> num) {
    if (num == 0)
      break;


    cin >> answer[0] >> answer[1];

    if (answer[1] == "high") {
      for (int i = num; i < 11; i++)
        verify[i] = false;
    } else if (answer[1] == "low") {
      for (int i = 1; i <= num; i++)
        verify[i] = false;
    } else { // right on
      if (verify[num]) {
        cout << "Stan may be honest" << endl;
      } else {
        cout << "Stan is dishonest" << endl;
      }
      memset(verify, true, sizeof verify);
    }
  }

  return 0;
}
