#include<bits/stdc++.h>
using namespace std;
vector<int> prefix(string s)
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
void kmp(string &text,string &pat)
{
	string s=pat+'#'+text;
	int r=pat.length();
	int l=s.length();
	vector<int>pi=prefix(s);
	bool flag=false;
    for(int i=0;i<=l-1;i++)
    {
        if(pi[i]==r)
        {
            cout<<i-2*r<<endl;
            flag=true;
        }
    }
    if(!flag)
        cout<<endl;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--)
	{
		string text,pat;
		cin>>text>>pat;
		kmp(text,pat);
	}
	return 0;
}
