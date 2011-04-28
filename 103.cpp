#include <iostream>
#include <algorithm>
using namespace std;

struct box {
  int num;
  int d;
  int dimensions[10];
};

struct result {
  int len;
  int pos;
};

// test if box a fits into box b
bool boxFits(const box &a, const box &b) {
  for (int i = 0; i < a.d; i++) {
    if (a.dimensions[i] >= b.dimensions[i])
      return false;
  }

  return true;
}

bool theTruthIsOutThere(const box &a, const box &b) {
  for (int i = 0; i < a.d; i++) {
    if (a.dimensions[i] >= b.dimensions[i]) {
      if (boxFits(b, a))
        return true;
      else
        return a.num > b.num;
    }
  }

  return false;
}

int main(void) {
  int n, k;
  box boxes[30];
  int dp[30];
  result best;
  result tmp;

  while (cin >> n >> k) {
    for (int i = 0; i < 30; i++)
      dp[i] = 1;

    best.pos = 0;
    best.len = 1;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < k; j++) {
        cin >> boxes[i].dimensions[j];
      }
      boxes[i].d = k;
      boxes[i].num = i + 1;
      sort(boxes[i].dimensions, boxes[i].dimensions + k);
    }

    sort(boxes, boxes + n, theTruthIsOutThere);

    for (int i = 0; i < n; i++) {
      if (boxes[i].num == 1)
        best.pos = i;
    }

    for (int i = 1; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (boxFits(boxes[i], boxes[j])) {
          dp[i] = max(dp[i], dp[j] + 1);
          if (dp[i] > best.len) {
            best.len = dp[i];
            best.pos = i;
          }
        }
      }
    }

    cout << best.len << endl;

    cout << boxes[best.pos].num;
    best.len--;
    while (best.len) {
      cout << " ";

      tmp.len = 2000000;
      tmp.pos = 0;
      for (int i = 0; i < best.pos; i++) {
        if (dp[i] == best.len && boxFits(boxes[best.pos], boxes[i])) {
          tmp.len = min(tmp.len, boxes[i].num);
          if (tmp.len == boxes[i].num)
            tmp.pos = i;
        }
      }

      cout << boxes[tmp.pos].num;
      best.pos = tmp.pos;

      best.len--;
    }
    cout << endl;
  }

  return 0;
}
