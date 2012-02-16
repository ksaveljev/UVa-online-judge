#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <vector>
#include <cmath>
using namespace std;

int read_account_number() {
  char c;
  int result = 0;

  for (int i = 0; i < 3; i++) {
    cin >> c;
    result = result * 10 + (c - '0');
  }

  return result;
}

int main(void)
{
  int account_number, old_transaction_number = -1, transaction_number, amount_in_dollars;
  string account_name;
  map<int, string> accounts;

  while (true) {
    account_number = read_account_number();
    getline(cin, account_name);

    if (account_number == 0) {
      break;
    }

    accounts[account_number] = account_name;
  }

  // keep the input order of transactions
  vector< pair<int, int> > payments;

  // verifying balance
  int balance = 0;

  while (true) {
    transaction_number = read_account_number();
    account_number = read_account_number();
    cin >> amount_in_dollars;

    // account_name is used as a filler to finish off the line
    getline(cin, account_name);

    if (old_transaction_number == -1 || transaction_number == old_transaction_number) {
      payments.push_back(make_pair(account_number, amount_in_dollars));
      balance += amount_in_dollars;
    } else {
      // transaction sequence number has changed, time to print a report
      // if the balance is anything other than zero
      if (balance != 0) {
        printf("*** Transaction %03d is out of balance ***\n", old_transaction_number);

        for (int i = 0, sz = payments.size(); i < sz; i++) {
          printf("%03d ", payments[i].first);
          printf("%-30s ", accounts[payments[i].first].c_str());
          printf("%10.2f\n", payments[i].second / 100.0);
        }

        balance *= -1;
        printf("999 Out of Balance                 %10.2f\n", balance / 100.0);

        cout << endl;
      }

      payments.clear();
      balance = 0;

      payments.push_back(make_pair(account_number, amount_in_dollars));
      balance += amount_in_dollars;
    }

    old_transaction_number = transaction_number;

    if (transaction_number == 0) {
      break;
    }
  }
  
  return 0;
}
