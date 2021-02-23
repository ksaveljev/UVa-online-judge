#include<bits/stdc++.h>
using namespace std;
int main()
{
	int r, c, count;
	char input[102][102], temp;
	for(int i=0; i<102; i++){input[0][i]='.'; input[i][0]='.';}
	do
	{
		cin>>r>>c;
		cin.ignore();
		if(r==0 && c==0) break;
		count=0;
		for(int i=1; i<=r; i++)
		{
			for(int j=1; j<=c; j++)
				cin.get(input[i][j]);
			cin.ignore();
			input[i][c+1]='.';
		}
		for(int i=1; i<=c+1; i++) input[r+1][i]='.';
		
		for(int i=1; i<=r; i++)
		{
			for(int j=1; j<=c; j++)
			{
				if(input[i][j]=='*')
				{
					if(!(input[i-1][j-1]=='*'||input[i-1][j]=='*'||input[i-1][j+1]=='*'||input[i][j-1]=='*'||input[i][j+1]=='*'||input[i+1][j-1]=='*'||input[i+1][j]=='*'||input[i+1][j+1]=='*'))count++;
				}
			}
		}
		cout<<count<<endl;
	}while(true);
	return 0;
}
