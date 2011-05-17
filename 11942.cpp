#include <iostream>
#include <algorithm>
using namespace std;

bool is_ordered(int len[10]) {
  bool result = true;

  for (int i = 1; i < 10; i++) {
    if (len[i] < len[i-1])
      return false;
  }

  return result;
}

int main(void) {
  int n;
  int len[10];

  cin >> n;

  cout << "Lumberjacks:" << endl;

  while (n--) {
    for (int i = 0; i < 10; i++)
      cin >> len[i];

    if (is_ordered(len)) {
      cout << "Ordered" << endl;
      continue;
    }

    reverse(len, len + 10);

    if (is_ordered(len)) {
      cout << "Ordered" << endl;
      continue;
    }

    cout << "Unordered" << endl;
  }

  return 0;
}
