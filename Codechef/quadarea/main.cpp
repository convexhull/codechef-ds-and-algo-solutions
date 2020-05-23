#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        long double a,b,c,d,s;
        cin>>a>>b>>c>>d;
        s=(a+b+c+d)/2;
        cout<<fixed<<sqrt((s-a)*(s-b)*(s-c)*(s-d))<<endl;
    }
    return 0;
}
