#include<bits/stdc++.h>
using namespace std;
string s;
vector<int> failure(string &s)
{
    int l=s.length();
    vector<int>pref(l);
    pref[0]=0;
    int border=0;
    for(int i=1;i<=l-1;i++)
    {
        while(border>0 && s[i]!=s[border])
            border=pref[border-1];
        if(s[i]==s[border])
            border++;
        else
            border=0;
        pref[i]=border;
    }
    return pref;
}
void kmp(string &text, string &pat)
{
    string s=pat+'$'+text;
    vector<int>pref=failure(s);
    int l=s.length();
    int r=pat.length();
    for(int i=0;i<=l-1;i++)
    {
        if(pref[i]==r)
            cout<<i-2*r<<endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string text,pat;
    cin>>text>>pat;
    kmp(text,pat);
    return 0;
}
