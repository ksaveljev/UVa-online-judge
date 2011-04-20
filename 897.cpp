#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

// anagrammatic primes can only contain 1 3 7 9 in it
// any other num will result in one of the permutations
// to be divisible by something
int digits[4] = {1, 3, 7, 9};
vector<int> aprimes;

bool is_prime(int n) {
  for (int i = 3, sq = sqrt(n); i <= sq; i++) {
    if (n % i == 0)
      return false;
  }
  return true;
}

bool is_anagrammatic_prime(int n) {
  int len = log10(n) + 1;
  int nums[8];
  int counter = 0;
  int tmp = n;
  int i;
  bool good;

  while (tmp) {
    nums[counter] = tmp % 10;
    tmp /= 10;
    counter++;
  }

  sort(nums, nums + len);

  good = true;

  do {
    tmp = 0;

    for (i = 0; i < len; i++)
      tmp = tmp * 10 + nums[i];

    if (!is_prime(tmp)) {
      good = false;
      break;
    }
  } while (next_permutation(nums, nums+len));

  return good ? true : false;
}

void generate_anagrammatic_primes(int num, int cur_depth, int depth) {
  if (cur_depth == depth) {
    if (is_anagrammatic_prime(num))
      aprimes.push_back(num);
    return;
  }

  for (int i = 0; i < 4; i++) {
    generate_anagrammatic_primes(num * 10 + digits[i], cur_depth + 1, depth);
  }
}

int main(void) {
  int n;

  aprimes.push_back(2);
  aprimes.push_back(3);
  aprimes.push_back(5);
  aprimes.push_back(7);

  for (int i = 2; i < 8; i++) {
    generate_anagrammatic_primes(0, 0, i);
  }

  sort(aprimes.begin(), aprimes.end());

  while (cin >> n) {
    if (n == 0)
      break;

    if (n >= aprimes[aprimes.size()-1]) {
      cout << "0" << endl;
      continue;
    }

    for (int i = 0, sz = aprimes.size(); i < sz; i++) {
      if (aprimes[i] > n) {
        if (aprimes[i] < pow(10, (int)log10(n) + 1))
          cout << aprimes[i] << endl;
        else
          cout << "0" << endl;
        break;
      }
    }
  }

  return 0;
}
