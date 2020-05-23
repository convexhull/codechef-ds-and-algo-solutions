#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long T;
    cin>>T;
    while(T--)
    {
        string s;
        cin>>s;
        long long l=s.length();
        long long cnt=0,ans=0;
        long long z;
        for(long long i=0;i<=l-1;i++)
        {
            long long flag=0;
            if(s[i]=='1')
            {
                cnt++;
            }
            if(s[i]=='0')
            {
                flag=1;
               for(long long x=i;s[x]!='1'&&x<=l-1;x++)
               {
                  ans+=cnt;
                  z=x;
               }
               ans+=cnt;
               if(flag)
                i=z;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
