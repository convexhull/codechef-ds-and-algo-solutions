#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<=n-1;i++)
        cin>>v[i];
    int k;
    cin>>k;
    for(int i=0;i<=n-k;i++)
    {
       cout<<*max_element(v.begin()+i,v.begin()+i+k)<<" ";
    }
    return 0;
}
