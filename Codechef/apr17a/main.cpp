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
        int c=0;
        map<string,int>mp;
        for(int i=1;i<=4;i++)
        {
            string s;
            cin>>s;
            mp[s]=1;
        }
        for(int i=1;i<=4;i++)
        {
            string s;
            cin>>s;
            if(mp[s]==1)
                c++;
        }
        if(c>=2)
        {
            cout<<"similar"<<endl;
        }
        else
            cout<<"dissimilar"<<endl;
    }
    return 0;
}
