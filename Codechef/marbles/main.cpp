#include<bits/stdc++.h>
using namespace std;
long long c(long long n,long long r)
{
    long long ans=1;
    for(long long i=n,j=1;j<=r;i--,j++)
    {
        ans=(i*ans)/j;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long T;
    cin>>T;
    while(T--)
    {
        long long n,k;
        cin>>n>>k;
        cout<<c(n-1,k-1)<<endl;
    }
    return 0;
}
