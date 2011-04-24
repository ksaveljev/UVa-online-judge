#include <iostream>
#include <set>
using namespace std;

int main(void) {
  int n, k, bill;
  unsigned long long result;
  multiset<int> bills;
  multiset<int>::iterator it1;
  multiset<int>::reverse_iterator it2;

  while (cin >> n) {
    if (n == 0)
      break;

    bills.clear();
    result = 0;

    for (int i = 0; i < n; i++) {
      cin >> k;
      while (k--) {
        cin >> bill;
        bills.insert(bill);
      }

      it1 = bills.begin();
      it2 = bills.rbegin();
      bill = *it2;

      result += *it2 - *it1;

      bills.erase(it1);
      it1 = bills.find(bill);
      bills.erase(it1);
    }

    cout << result << endl;
  }

  return 0;
}
