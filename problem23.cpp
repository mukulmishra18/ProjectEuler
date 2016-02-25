#include <bits/stdc++.h>
using namespace std;

vector<int> ve;
vector<int> ans;

int propdiv(int n)
{
	int i, sum = 1;

	for(i=2; i<sqrt(n); i ++)
	{
		if(n % i == 0)
		{
			sum += (i + (n/i));
		}
	}
	if(i == sqrt(n))
		sum += i;

	return sum;
} 

void pre()
{
	int i, j;

	for(i=2; i<=15000; i++)
	{
		if(propdiv(i) > i)
			ve.push_back(i);
	}

	for(i=0; i<ve.size(); i++)
	{
		for(j=i; j<ve.size(); j++)
		{
			int temp = ve[i] + ve[j];
			ans.push_back(temp);
		}
	}
}

int main()
{
	int i;

	pre();
	sort(ans.begin(), ans.end());

	//cout << ve.size() << " " << ans.size() << endl;
	/*for(i=0; i<20; i++)
	{
		cout << ve[i] << " " << ans[i] << endl;
	}*/

	//cout << endl;

	int t;
	cin >> t;

	while(t--)
	{
		int n;
		cin >> n;

		if(n > 28123)
			cout << "YES" << endl;
		else
		{
			if(binary_search(ans.begin(), ans.end(), n))
				cout << "YES" << endl;
			else
				cout << "NO" << endl;		
		}
	}
	return 0;
}
