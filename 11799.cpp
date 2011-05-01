#include <iostream>
using namespace std;

int main(void) {
  int cases, tmp;
  int students, result;

  cin >> cases;

  for (int i = 0; i < cases; i++) {
    result = 0;
    cin >> students;
    for (int j = 0; j < students; j++) {
      cin >> tmp;
      if (tmp > result)
        result = tmp;
    }

    cout << "Case " << i + 1 << ": " << result << endl;
  }

  return 0;
}
