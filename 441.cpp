#include <iostream>
#include <map>
using namespace std;

int k;
long tmp;
int s[20];
int result[10];

void do_stuff(int pos, int nums) {
  if (nums == 6) {
    for (int i = 0; i < 6; i++) {
      if (i > 0)
        cout << " ";
      cout << result[i];
    }
    cout << endl;

    return;
  }

  for (int i = pos; i < k; i++) {
    result[nums] = s[i];
    do_stuff(i+1, nums+1);
  }
}

int main(void) {
  bool first = true;

  while (cin >> k) {
    if (k == 0)
      break;

    for (int i = 0; i < k; i++)
      cin >> s[i];

    if (!first)
      cout << endl;

    do_stuff(0, 0);

    first = false;
  }

  return 0;
}
