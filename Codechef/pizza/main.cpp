#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    map<string,int>mp;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        mp[s]++;
    }
    int ans=1;
    ans+=mp["3/4"];
    //cout<<ans<<endl;
    int left4=mp["3/4"];
    ans+=ceil(mp["1/2"]/(double)2);
    //cout<<ans<<endl;
    int left2=0;
    if(mp["1/2"]%2!=0)
        left2=1;
    int p=max(0,(int)(ceil((mp["1/4"]-left4-2*left2)/4.0)));
    ans+=p;
    cout<<ans;
    return 0;
}
