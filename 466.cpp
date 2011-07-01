#include <iostream>
using namespace std;

bool is_same(char field[][10], char modified[][10], int n)
{
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (field[i][j] != modified[i][j]) {
        return false;
      }
    }
  }

  return true;
}

void rotate(char modified[][10], int n)
{
  char tmp[10][10];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      tmp[i][j] = modified[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      modified[i][j] = tmp[n-j-1][i];
    }
  }
}

void reflect(char modified[][10], int n)
{
  char tmp[10][10];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      tmp[i][j] = modified[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      modified[i][j] = tmp[n-i-1][j];
    }
  }
}

int main(void)
{
  int n;
  char c;
  int casenum = 0;
  char field[10][10];
  char modified[10][10];

  while (cin >> n) {
    casenum++;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> field[i][j];
      }

      for (int j = 0; j < n; j++) {
        cin >> modified[i][j];
      }
    }

    if (is_same(field, modified, n)) {
      cout << "Pattern " << casenum << " was preserved." << endl;
      continue;
    }

    rotate(field, n);
    if (is_same(field, modified, n)) {
      cout << "Pattern " << casenum << " was rotated 90 degrees." << endl;
      continue;
    }

    rotate(field, n);
    if (is_same(field, modified, n)) {
      cout << "Pattern " << casenum << " was rotated 180 degrees." << endl;
      continue;
    }

    rotate(field, n);
    if (is_same(field, modified, n)) {
      cout << "Pattern " << casenum << " was rotated 270 degrees." << endl;
      continue;
    }

    rotate(field, n);

    reflect(field, n);
    if (is_same(field, modified, n)) {
      cout << "Pattern " << casenum << " was reflected vertically." << endl;
      continue;
    }

    rotate(field, n);
    if (is_same(field, modified, n)) {
      cout << "Pattern " << casenum << " was reflected vertically and rotated 90 degrees." << endl;
      continue;
    }

    rotate(field, n);
    if (is_same(field, modified, n)) {
      cout << "Pattern " << casenum << " was reflected vertically and rotated 180 degrees." << endl;
      continue;
    }

    rotate(field, n);
    if (is_same(field, modified, n)) {
      cout << "Pattern " << casenum << " was reflected vertically and rotated 270 degrees." << endl;
      continue;
    }

    cout << "Pattern " << casenum << " was improperly transformed." << endl;
  }
  
  return 0;
}
