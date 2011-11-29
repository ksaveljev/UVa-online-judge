#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

void add_range(int start, int end) {
  stack<int> s_start, s_end;

  while (start) {
    s_start.push(start % 10);
    start /= 10;
  }

  while (end) {
    s_end.push(end % 10);
    end /= 10;
  }

  while (s_start.top() == s_end.top()) {
    s_start.pop();
    s_end.pop();
  }

  cout << "-";

  while (!s_end.empty()) {
    cout << s_end.top();
    s_end.pop();
  }

  cout << endl;
}

void print_results(vector<int>& numbers) {
  if (numbers.size() == 0) {
    return;
  }

  bool flag = false;
  int start = numbers[0];

  cout << "0" << numbers[0];

  for (int i = 1, sz = numbers.size(); i < sz; i++) {
    if (numbers[i] - numbers[i-1] == 1) {
      flag = true;
      continue;
    } else {
      if (flag) {
        add_range(start, numbers[i-1]);
      } else {
        cout << endl;
      }
      flag = false;
      start = numbers[i];
      cout << "0" << numbers[i];
    }
  }

  if (flag) {
    add_range(start, numbers[numbers.size()-1]);
  } else {
    cout << endl;
  }
}

int main(void)
{
  int n, number, case_num = 0;
  vector<int> numbers;

  while (cin >> n) {
    if (n == 0) {
      break;
    }

    case_num++;
    numbers.clear();

    while (n--) {
      cin >> number;
      numbers.push_back(number);
    }

    sort(numbers.begin(), numbers.end());

    cout << "Case " << case_num << ":" << endl;
    print_results(numbers);

    cout << endl;
  }
  
  return 0;
}
