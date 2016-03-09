#include <bits/stdc++.h>
using namespace std;

int a[7] = {0};

void solve(int n)
{
	for(int i=1; i<=6; i++)
	{
		int temp = n, ans = 0;

		while(temp > 0)
		{
			int x;
			x = temp%10;

			ans += pow(x, i);
			temp /= 10; 
		}

		if(ans == n)
			a[i] += n;
	}
}

void pre()
{
	int i;

	for(i=100; i<=600000; i++)
	{
		solve(i);
	}
}

int main()
{
	pre();

	int n;
	cin >> n;

	cout << a[n] << endl;
	
	return 0;
}
