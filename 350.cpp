#include <iostream>
#include <map>
using namespace std;

int main(void) {
	int next;
	int seed;
	int result;
	int cases = 0;
	int Z, I, M, L;
	map<int,bool> visited;

	while (cin >> Z >> I >> M >> L) {
		if (Z == 0 && I == 0 && M == 0 && L == 0)
			break;

		cases++;
		seed = L;
		result = 0;
		visited.clear();
	
		while (true) {
			next = (Z * L + I) % M;
			if (next == seed) {
				result++;
				break;
			} else if (visited[next] == true) {
				break;
			}

			L = next;
			visited[L] = true;

			result++;
		}

		cout << "Case " << cases << ": " << result << endl;
	}

	return 0;
}
