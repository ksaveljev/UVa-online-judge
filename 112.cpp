#include <iostream>
#include <stack>
using namespace std;

int main (void) {
	long n; 			// the value we are searching for
	stack<int> nodes; 	// the values in the nodes (stored temporarily)
	int opened; 		// num of unclosed '('
	char c; 			// char to read input tree
	char prev;			// previous char, needed to find ()()
	long node;			// current value in the node
	long sum;			// summing the nodes
	int bottomnode;		// if there are () two times together - then it is the bottom node
	bool found;			// if the solution is found
	int sign;			// current sign of the node value
	
	while (cin >> n) {
		// each new case - we reset the values
		opened = 0;
		sum = 0;
		node = 0;
		bottomnode = 0;
		prev = 'a';
		sign = 1;
		found = false;
		
		// emptying stack
		while (!nodes.empty())
			nodes.pop();
		
		// reading chars one by one - we only consider '(' ')' '0'..'9' and '-'
		while (c = getchar()) {
			// when we find the opening bracet
			if (c == '(') {
				// we check if it is the first one in the case or not
				// if it is the first one then it's just a formality
				// and the only thing we need to do is to increment
				// the counter of opened bracets
				if (opened > 0) {
					// so this is not the first opened bracet
					
					// we check if the previous char was the closing bracet
					// if it was then there was no node value before '('
					// and we don't need to enter the scope
					if (prev != ')') {
						// so the previous char was not ')'
						// then we had a value before the opening bracet
						// and we push it into our stack
						sum += node;
						nodes.push (node);
						// we also reset the node value
						node = 0;
						// and we reset the sign of the node value (for further reading)
						sign = 1;
					}
				}
				// just incrementing the amount of opened bracets
				// this value is required in order to find out when
				// the test case finished (opened == 0)
				++opened;
			// in case of the closing bracet
			} else if (c == ')') {
				// we check if the previous char was the opening bracet
				if (prev == '(') {
					// if it was then we have met the structure '()'
					// we require this knowledge in order to find out
					// when we have met the bottom node which has no
					// children nodes... so when the bottomnode == 2
					// we are at the bottom of the tree
					++bottomnode;
				} else {
					// so the previous char was not '('
					// it means we are going up one node
					// we decrease the sum by the node we
					// are currently at
					sum -= nodes.top();
					// remove it from stack
					nodes.pop();
					// reset the bottomnode flag -- had some bugs here
					// very rare test cases on the forum could actually
					// break my code without this line
					bottomnode = 0;
				}
				
				// now we can check whether are in the bottom of the tree
				// (which means that we have to check our sum with the sum
				// needed)
				if (bottomnode == 2) {
					// if the sum is the same as required we set the
					// found flag to true... and just continue to 
					// work with the tree like we have not found 
					// anything but in the end we will print out
					// that we have found the needed sum
					if (sum == n)
						found = true;
					// reset the bottomnode
					bottomnode = 0;
				}
				
				// as soon as it was the closing bracet we need to
				// decrease the amount of opened bracets
				--opened;
				
				// and if the amount of opened bracets is 0
				// then we have finished reading this test case
				// and can proceed to printing the result
				if (opened == 0) break;
			// if the char is minus then we set the sign to -1 in order
			// to get the appropriate node value
			} else if (c == '-') {
				sign = -1;
			// when we get these types of chars then we are reading
			// the node value
			} else if (c >= '0' && c <= '9') {
				// we get the node value and it depends on the sign
				node = node * 10 + sign * (c - 48);
				// we also reset the bottomnode flag here... it was
				// my second bug -- only 1 test input on the forum
				// actually showed me this mistake...
				bottomnode = 0;
			}
			
			// we save the previous character if and only if it is among
			// those we are interested in (no spaced and newlines are saved)
			if (c == '(' || c == ')' || c >= '0' && c <= '9' || c == '-')
				prev = c;
		}
		
		// pritty simple - huh?
		if (found) cout << "yes" << endl;
		else cout << "no" << endl;
	}
	
	return 0;
}