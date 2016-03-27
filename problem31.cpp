#include <bits/stdc++.h>
using namespace std;

const long long int M = 1000000007;
long long int DP[8][100001];

void pre()
{
	int i, j;

	int coins[] = {1, 2, 5, 10, 20, 50, 100, 200};


	for(i=0; i<8; i++) 
		DP[i][0] = 1;

	for(j=1; j<=100000; j++) 
		DP[0][j] = 1;    

	for(i=1; i<8; i++)
	{
		for(j=1; j<=100000; j++)
		{
			if(j >= coins[i])
				DP[i][j] = ((DP[i-1][j]%M) + (DP[i][j - coins[i]]%M))%M;
			else
				DP[i][j] = (DP[i-1][j])%M;
		}
	}

}

int main()
{
	clock_t begin = clock();
	pre();
	clock_t end = clock();

	cout << "Time taken to precompute is " << (double(end - begin)/CLOCKS_PER_SEC) << "s" << endl;
	int t;
	scanf("%d", &t);

	while(t--)
	{

		long int total;
		
		cin >> total;

		printf("%lld\n",DP[7][total]);
	}
	return 0;
}
