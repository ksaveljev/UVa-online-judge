#include <iostream>
#include <queue>
using namespace std;

int main (void) {
	priority_queue< int, vector<int>, greater<int> > ugly;
	
	ugly.push(2);
	ugly.push(3);
	ugly.push(5);
	
	int count = 1;
	int current = 1;
	
	while (count < 1500) {
		int temp = 0;
		while (temp <= current) {
			temp = ugly.top();
			ugly.pop();
		}
		
		ugly.push(2*temp);
		ugly.push(3*temp);
		ugly.push(5*temp);
		
		current = temp;
		count++;
	}
	
	cout << "The 1500'th ugly number is " << current << "." << endl;
	
	return 0;
}