#include<bits/stdc++.h>
using namespace std;
vector<int> pref(string s)
{
    int l=s.length();
	vector<int>pi(l);
	pi[0]=0;
	int lb=0;
	for(int i=1;i<=l-1;i++)
	{
		if(s[i]==s[lb])
		{
			lb++;
			pi[i]=lb;
		}
		else
		{
			while(lb>0 && s[i]!=s[lb])
				lb=pi[lb-1];
			if(s[i]==s[lb])
			{
				lb++;
				pi[i]=lb;
			}
			else
				pi[i]=0;
		}
	}
    return pi;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin>>s;
    vector<int>pi=pref(s);
    for(int i=0;i<=pi.size()-1;i++)
        cout<<pi[i]<<" ";
    return 0;
}
