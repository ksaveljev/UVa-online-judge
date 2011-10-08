#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
  int file_size, transfer_size;
  int case_num = 0;
  vector<int> file_transfer;

  while (cin >> file_size) {
    if (file_size == 0) {
      break;
    }

    case_num++;
    file_transfer.clear();

    cout << "Output for data set " << case_num << ", " << file_size << " bytes:" << endl;
    while (file_size > 0) {
      cin >> transfer_size;
      file_transfer.push_back(transfer_size);
      file_size -= transfer_size;

      if (file_transfer.size() % 5 == 0) {
        int bytes_transferred = 0;
        for (int i = 0; i < 5; i++) {
          bytes_transferred += file_transfer[file_transfer.size() - 1 - i];
        }

        if (bytes_transferred == 0) {
          cout << "   Time remaining: stalled" << endl;
        } else {
          double tmp = file_size * 5.0 / bytes_transferred;
          int time_remaining = (tmp > int(tmp) ? int(tmp) + 1 : int(tmp));
          cout << "   Time remaining: " << time_remaining << " seconds" << endl;
        }
      }
    }

    cout << "Total time: " << file_transfer.size() << " seconds" << endl;
    cout << endl;
  }
  
  return 0;
}
