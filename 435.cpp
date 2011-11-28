#include <iostream>
using namespace std;

int result[20];
int parties[20];
bool taken[20];

void compute(int index, int p, int sum, int limit) {
  for (int i = 0; i < p; i++) {
    if (taken[i]) {
      continue;
    }

    taken[i] = true;
    if (sum + parties[i] > limit) {
      result[i]++;
    } else {
      if (i >= index) {
        compute(i, p, sum + parties[i], limit);
      }
    }
    taken[i] = false;
  }
}

void solve(int p, int limit) {
  for (int i = 0; i < 20; i++) {
    result[i] = 0;
    taken[i] = false;
  }

  compute(0, p, 0, limit);
}

int main(void)
{
  int cases, p, total;

  cin >> cases;

  while (cases--) {
    cin >> p;
    
    total = 0;

    for (int i = 0; i < p; i++) {
      cin >> parties[i];
      total += parties[i];
    }

    solve(p, total/2);

    for (int i = 0; i < p; i++) {
      cout << "party " << i+1 << " has power index " << result[i] << endl;
    }

    cout << endl;
  }
  
  return 0;
}
