#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int  T;
    cin>>T;
    int  c=0;
    while(T--)
    {
        c++;
        int  n;
        cin>>n;
        if(n==0)
        {
            cout<<"Case "<<c<<": "<<0<<endl;
            continue;
        }
        if(n==1)
        {
            int a;
            cin>>a;
            cout<<"Case "<<c<<": "<<a<<endl;
            continue;
        }
        vector<int>v(n);
        for(int  i=0;i<=n-1;i++)
            cin>>v[i];
        vector<long long>dp(n);
        dp[0]=v[0];
        dp[1]=max(v[0],v[1]);
        for(int  i=2;i<=n-1;i++)
        {
            dp[i]=max(dp[i-1],dp[i-2]+v[i]);
        }
        cout<<"Case "<<c<<": "<<dp[n-1]<<endl;
    }
    return 0;
}
