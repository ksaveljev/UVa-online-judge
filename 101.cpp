#include <iostream>
#include <string>
using namespace std;

int main (void) {
	int n, a, b;
	string command, place;
	int posa[2];
	int posb[2];
	
	cin >> n;
	
	int tbl[n][n];
	
	// clearing table
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			tbl[i][j] = -1;
		
	// setting up n blocks
	for (int i = 0; i < n; i++)
		tbl[i][0] = i;
	
	// start executing commands
	while (cin >> command) {
		if (command == "quit")
			break;
		
		cin >> a >> place >> b;
		
		if (a == b) continue;
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (tbl[i][j] == a) {
					posa[0] = i;
					posa[1] = j;
				}
				if (tbl[i][j] == b) {
					posb[0] = i;
					posb[1] = j;
				}
			}
		}
		
		if (posa[0] == posb[0]) continue;
		
		if (command == "move") {
			if (place == "onto") {
				// removing everything from a and b
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						if (tbl[i][j] == a || tbl[i][j] == b) {
							for (int y = j + 1; y < n; y++) {
								if (tbl[i][y] == -1) break;
								tbl[tbl[i][y]][0] = tbl[i][y];
								tbl[i][y] = -1;
							}
						}
					}
				}
				
				bool found = false;
				
				// searching for b
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						if (tbl[i][j] == b) {
							// saving position to place a
							posb[0] = i;
							posb[1] = j + 1;
							found = true;
							break;
						}
					}
					if(found) break;
				}
				
				bool moved = false;
				
				// searching for a
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						if (tbl[i][j] == a) {
							// removing a from its position
							tbl[i][j] = -1;
							// setting new position for a
							tbl[posb[0]][posb[1]] = a;
							break;
						}
					}
					if (moved) break;
				}
			} else if (place == "over") {
				// removing everything from a
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						if (tbl[i][j] == a ) {
							posa[0] = i;
							posa[1] = j;
							for (int y = j + 1; y < n; y++) {
								if (tbl[i][y] == -1) break;
								tbl[tbl[i][y]][0] = tbl[i][y];
								tbl[i][y] = -1;
							}
						}
					}
				}
				
				bool found = false;
				
				// searching for b pile
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						if (tbl[i][j] == b) {
							found = true;
						}
						if (tbl[i][j] == -1) {
							if (found) {
								posb[0] = i;
								posb[1] = j;
							}
							break;
						}
					}
					if (found) break;
				}
				
				// removing a
				tbl[posa[0]][posa[1]] = -1;
				// setting a 
				tbl[posb[0]][posb[1]] = a;
			}
		} else if (command == "pile") {
			if (place == "onto") {
				bool found = false;
				// searching for b
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						if (tbl[i][j] == -1) break;
						if (tbl[i][j] == b) {
							posb[0] = i;
							posb[1] = j + 1;
							
							found = true;
							
							for (int y = j + 1; y < n; y++) {
								if (tbl[i][y] == -1) break;
								tbl[tbl[i][y]][0] = tbl[i][y];
								tbl[i][y] = -1;
							}
							break;
						}
					}
					if (found) break;
				}
				
				found = false;
				
				// searching for a
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						if (tbl[i][j] == a) {
							found = true;
							posa[0] = i;
							posa[1] = j;
							break;
						}
					}
					if (found) break;
				}
				
				// moving all blocks onto b
				for (int i = posa[1]; i < n; i++) {
					if (tbl[posa[0]][i] == -1) break;
					
					tbl[posb[0]][posb[1]] = tbl[posa[0]][i];
					tbl[posa[0]][i] = -1;
					
					posb[1]++;
				}
			} else if (place == "over") {
				bool found = false;
				
				// searching for a
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						if (tbl[i][j] == -1) break;
						
						if (tbl[i][j] == a) {
							posa[0] = i;
							posa[1] = j;
							found = true;
							break;
						}
					}
					if (found) break;
				}
				
				found = false;
				// searching for b
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						if (tbl[i][j] == -1) break;
						
						if (tbl[i][j] == b) {
							for (int y = j + 1; y < n; y++) {
								if (tbl[i][y] == -1) {
									posb[0] = i;
									posb[1] = y;
									break;
								}
							}
							found = true;
							break;
						}
					}
					if (found) break;
				}
				
				// setting a pile over b pile
				for (int i = posa[1]; i < n; i++) {
					if (tbl[posa[0]][i] == -1) break;
					
					tbl[posb[0]][posb[1]] = tbl[posa[0]][i];
					tbl[posa[0]][i] = -1;
					
					posb[1]++;
				}
			}
		}
	}
	
	// display results:
	for (int i = 0; i < n; i++) {
		cout << i << ":";
		for (int j = 0; j < n; j++) {
			if (tbl[i][j] == -1) break;
			cout << " " << tbl[i][j];
		}
		cout << endl;
	}
	
	return 0;
}