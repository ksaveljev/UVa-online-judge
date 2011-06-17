#include <iostream>
using namespace std;

int main(void) {
  int n;
  int correct[1000], guess[1000];
  int correct_count[10], guess_count[10], correct_count_copy[10];
  int counter = 0;

  while (cin >> n) {
    if (!n)
      break;
    
    counter++;

    cout << "Game " << counter << ":" << endl;

    for (int i = 0; i < 10; i++)
      correct_count[i] = 0;

    for (int i = 0; i < n; i++) {
      cin >> correct[i];
      correct_count[correct[i]]++;
    }

    while (true) {
      int strong = 0;
      int weak = 0;
      bool empty = true;

      for (int i = 0; i < 10; i++)
        guess_count[i] = 0;

      for (int i = 0; i < 10; i++)
        correct_count_copy[i] = correct_count[i];

      for (int i = 0; i < n; i++) {
        cin >> guess[i];
        if (guess[i] > 0)
          empty = false;

        if (guess[i] == correct[i]) {
          strong++;
          correct_count_copy[correct[i]]--;
        } else {
          guess_count[guess[i]]++;
        }
      }

      if (empty)
        break;

      for (int i = 1; i < 10; i++)
        weak += min(correct_count_copy[i], guess_count[i]);

      cout << "    (" << strong << "," << weak << ")" << endl;
    }
  }

  return 0;
}
