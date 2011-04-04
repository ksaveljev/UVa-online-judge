#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <vector>
using namespace std;

int main (void) {
	string w1, w2;
	
	while (cin >> w1) {
		if (w1 == "#") break;
		cin >> w2;
		
		int dp[w1.size() + 1][w2.size() + 1];
		
		// Levenshtein Distance - dynamic programming
		for (int i = 0; i < w1.size() + 1; i++) dp[i][0] = i;
		for (int i = 0; i < w2.size() + 1; i++) dp[0][i] = i;
		
		for (int i = 1; i < w1.size() + 1; i++) {
			for (int j = 1; j < w2.size() + 1; j++) {
				int cost;
				if (w1[i-1] == w2[j-1]) cost = 0; else cost = 1;
				dp[i][j] = min(dp[i-1][j] + 1, min(dp[i][j-1] + 1, dp[i-1][j-1] + cost));
			}
		}
		// Levenshtein Distance end
		
		// surfing through the matrix to find the commands we need
		// to execute in order to get the best(minimum) result
		int i = w1.size(), j = w2.size();
		
		char buf[25];
		vector <string > commands;
		while(i>0 && j>0){ 
		      if(dp[i-1][j] + 1 == dp[i][j]){ 
		         sprintf(buf,"D%c%02d",w1[i-1],j+1); 
		         i--; 
		      } 
		      else if(dp[i][j-1]+1 == dp[i][j]){ 
		         sprintf(buf,"I%c%02d",w2[j-1],j); 
		         j--; 
		      } 
		      else { 
		         if(w1[--i] != w2[--j])sprintf(buf,"C%c%02d",w2[j],j+1); 
		         else            continue; 
		      } 
		      commands.push_back(string(buf)); 
		   } 
		   while(i>0){ 
		      sprintf(buf,"D%c%02d",w1[--i],1); 
		      commands.push_back(string(buf)); 
		   } 
		   while(j>0){ 
		      sprintf(buf,"I%c%02d",w2[j-1],j); 
		      commands.push_back(string(buf)); 
		      j--; 
		   } 
		   string instr = ""; 
		   for(int k = commands.size()-1;k >= 0;k--) 
		      instr += commands[k]; 
		   instr += 'E';
		
		cout << instr;
		cout << endl;
		
		//cout << dp[w1.size()][w2.size()] << endl;
	}
	
	
	return 0;
}