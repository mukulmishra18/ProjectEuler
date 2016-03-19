#include <bits/stdc++.h>
using namespace std;

set<long int> s4, s5, s6, s7, s8, s9;

bool ispandigit(string temp)
{
	int i, a[10] = {0}, flag;

	for(i=0; i<temp.size(); i++)
	{
		a[temp[i] - 48]++;
	}

	if(a[0] == 0)
		flag = 1;
	else
		flag = 0;

	i = 1;
	while(a[i] == 1)
		i++;

	while(i<10)
	{
		if(a[i]>0)
			flag = 0;
		i++;
	}

	if(flag == 1)
		return true;
	else
		return false;
}

void pre()
{
	int i, j, pro, start, end;
	string temp, st_i, st_j, st_pro;

	for(i=2; i<100; i++)
	{
		//start = (i>9) ? 123 : 1234;
		end = 10000/i;

		for(j=2; j<end; j++)
		{
			pro = i*j;
			temp = to_string(i) + to_string(j) + to_string(pro);
			if(ispandigit(temp))
			{
				if(temp.size() == 4)
					s4.insert(pro);
				if(temp.size() == 5)
					s5.insert(pro);
				if(temp.size() == 6)
					s6.insert(pro);
				if(temp.size() == 7)
					s7.insert(pro);
				if(temp.size() == 8)
					s8.insert(pro);
				if(temp.size() == 9)
					s9.insert(pro);
			}
		}
	}
}

int main()
{
	pre();
	set<long int>::iterator it;

	//for(it=s4.begin(); it!=s4.end(); it++)
		//cout << (*it) << endl;

	int n, ans[10] = {0};

	for(it=s4.begin(); it!=s4.end(); it++)
		ans[4] += (*it);
	for(it=s5.begin(); it!=s5.end(); it++)
		ans[5] += (*it);
	for(it=s6.begin(); it!=s6.end(); it++)
		ans[6] += (*it);
	for(it=s7.begin(); it!=s7.end(); it++)
		ans[7] += (*it);
	for(it=s8.begin(); it!=s8.end(); it++)
		ans[8] += (*it);
	for(it=s9.begin(); it!=s9.end(); it++)
		ans[9] += (*it);
	
	cin >> n;
	cout << ans[n] << endl;
	return 0;
}
