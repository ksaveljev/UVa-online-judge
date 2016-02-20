#include <iostream>
#include <string>
using namespace std;

int main (void) {
	unsigned int bottles[9];
	
	while (cin >> bottles[0]) {
		for (int i = 1; i < 9; i++) cin >> bottles[i];
		
		unsigned int min = 1 << 31;
		string minimum = "BGC";
		
		// B G C B G C B G C
		// 0 1 2 3 4 5 6 7 8
		
		// BCG
		if (bottles[3] + bottles[6] + bottles[2] + bottles[8] + bottles[1] + bottles[4] < min){
			minimum = "BCG";
			min = bottles[3] + bottles[6] + bottles[2] + bottles[8] + bottles[1] + bottles[4];
		}
		// BGC
		if (bottles[3] + bottles[6] + bottles[1] + bottles[7] + bottles[2] + bottles[5] < min){
			minimum = "BGC";
			min = bottles[3] + bottles[6] + bottles[1] + bottles[7] + bottles[2] + bottles[5];
		}
		// CBG
		if (bottles[5] + bottles[8] + bottles[0] + bottles[6] + bottles[1] + bottles[4] < min){
			minimum = "CBG";
			min = bottles[5] + bottles[8] + bottles[0] + bottles[6] + bottles[1] + bottles[4];
		}
		// CGB
		if (bottles[5] + bottles[8] + bottles[1] + bottles[7] + bottles[0] + bottles[3] < min){
			minimum = "CGB";
			min = bottles[5] + bottles[8] + bottles[1] + bottles[7] + bottles[0] + bottles[3];
		}
		// GBC
		if (bottles[4] + bottles[7] + bottles[0] + bottles[6] + bottles[2] + bottles[5] < min){
			minimum = "GBC";
			min = bottles[4] + bottles[7] + bottles[0] + bottles[6] + bottles[2] + bottles[5];
		}
		// GCB
		if (bottles[4] + bottles[7] + bottles[2] + bottles[8] + bottles[0] + bottles[3] < min){
			minimum = "GCB";
			min = bottles[4] + bottles[7] + bottles[2] + bottles[8] + bottles[0] + bottles[3];
		}
		
		cout << minimum << " " << min << endl;
	}
	
	return 0;
}
/* Hello sir,
    First of all, I would like to thank you for the UVa online judge exercises
    that you have posted on your github repository. They have really helped
    me with the exercises I struggled with and I really admire your intelligencein solving some difficult problems.
    I am taking a Competitive programming course in my university. In the first quiz I did 1/2 exercises and I lost
    10% of the final grade. I cannot afford to lose many points because I have to maintain a 3.5 GPA
    and I am in a very stresful situation at the moment, because the professor assumes
    we have some experience in competitive  programming, which I don't.
    I would be really grateful if you could help me.Thank you
    Best regards.
*/
