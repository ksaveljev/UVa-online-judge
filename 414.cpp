#include <iostream>
using namespace std;

#define COLUMN_NUM 25
#define ROW_NUM_MAX 12

int main(void) {
	int N, length, result, shortest;
	char input[COLUMN_NUM];
	int len[ROW_NUM_MAX];
	
	while (cin >> N) {
		if (!N) break;
		
		cin.getline(input, 256); // getting \n
		shortest = COLUMN_NUM + 1;
		
		for (int i = 0; i < N; i++) {
			cin.getline(input, 256);
			length = 0;
			for (int y = 0; y < COLUMN_NUM; y++) {
				if (input[y] == ' ')
					length++;
			}
			
			len[i] = length;
			if (length < shortest)
				shortest = length;
		}
		
		result = 0;
		
		for (int i = 0; i < N; i++)
			result += len[i] - shortest;
		
		cout << result << endl;
	}
	
	return 0;
}
