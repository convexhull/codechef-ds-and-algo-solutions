#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        vector<int>v(n);
        for(int i=0;i<=n-1;i++)
            cin>>v[i];
        vector<int>dp(n);
        for(int i=0;i<=n-1;i++)
        {
            int len=0,val=0;
            for(int j=0;j<=i;j++)
            {
                if(v[j]<=v[i])
                    val=1+dp[j];
                else val=1;
                len=max(len,val);
            }
            dp[i]=len;
        }
        cout<<*max_element(dp.begin(),dp.end())<<endl;
    }
    return 0;
}
