#include <iostream>
#include <vector>
using namespace std;

int main(void) {
  int a, b;
  int counter;
  vector<int> square_numbers;

  for (int i = 1; i < 317; i++) {
    square_numbers.push_back(i*i);
  }

  while (cin >> a >> b) {
    if (a == 0 && b == 0)
      break;

    counter = 0;
    for (int i = 0, sz = square_numbers.size(); i < sz; i++) {
      if (square_numbers[i] >= a && square_numbers[i] <= b)
        counter++;
    }

    cout << counter << endl;
  }

  return 0;
}
