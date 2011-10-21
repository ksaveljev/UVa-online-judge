#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int sz;

vector<int> number_of_determinate_primes(vector<int>& primes, int n) {
  vector<int> result;
  int diff = -1;

  for (int i = n+1; i < sz; i++) {
    if (diff == -1) {
      result.push_back(primes[i-1]);
      result.push_back(primes[i]);
      diff = primes[i] - primes[i-1];
    } else {
      if (diff == primes[i] - primes[i-1]) {
        result.push_back(primes[i]);
      } else {
        break;
      }
    }
  }

  return result;
}

bool is_prime(int n) {
  for (int i = 3, sq = sqrt(n); i <= sq; i+=2) {
    if (n % i == 0) {
      return false;
    }
  }

  return true;
}

void print_sequence(vector<int> v) {
  for (int i = 0; i < v.size(); i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << v[i];
  }
  cout << endl;
}

int main(void)
{
  vector<int> primes;
  vector< vector<int> > seq;

  primes.push_back(2);
  for (int i = 3; i < 32000; i+=2) {
    if (is_prime(i)) {
      primes.push_back(i);
    }
  }

  sz = primes.size();

  for (int i = 0; i < sz; i++) {
    vector<int> tmp = number_of_determinate_primes(primes, i);
    if (tmp.size() > 2) {
      seq.push_back(tmp);
      i += tmp.size() - 2;
    }
  }

  int a, b;
  sz = seq.size();

  while (cin >> a >> b) {
    if (a == 0 && b == 0) {
      break;
    }

    if (a > b) {
      swap(a, b);
    }

    for (int i = 0; i < sz; i++) {
      if (seq[i][0] >= a && seq[i][seq[i].size()-1] <= b) {
        print_sequence(seq[i]);
      }
    }
  }
  
  return 0;
}
