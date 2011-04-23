#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
  int n;
  int rows;
  int columns;
  int longest = 0;
  string file;
  vector<string> files;

  while (cin >> n) {
    longest = 0;
    files.clear();

    for (int i = 0; i < n; i++) {
      cin >> file;
      files.push_back(file);
      if (file.size() > longest)
        longest = file.size();
    }

    sort(files.begin(), files.end());

    columns = 60 / longest;
    while (longest * columns + 2 * (columns - 1) > 60)
      columns--;

    rows = files.size() / columns;
    if (rows * columns < files.size())
      rows++;

    for (int i = 0; i < 60; i++)
      cout << "-";
    cout << endl;

    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < columns && j*rows+i < files.size(); j++) {
        cout << files[j * rows + i];

        for (int k = 0; k < longest - files[j*rows+i].size(); k++)
          cout << " ";

        if (j < columns - 1)
          cout << "  ";
      }
      cout << endl;
    }
  }

  return 0;
}
