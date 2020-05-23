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
        string s;
        cin>>s;
        string s2=s;
        reverse(s2.begin(),s2.end());
        int l=s.length();
        vector< vector<int> >v(l+1,vector<int>(l+1));
        for(int i=1;i<=l;i++)
        {
            for(int j=1;j<=l;j++)
            {
                if(s[i-1]==s2[j-1])
                    v[i][j]=v[i-1][j-1]+1;
                else
                    v[i][j]=max(v[i-1][j],v[i][j-1]);
            }
        }
        cout<<l-v[l][l]<<endl;
    }
    return 0;
}
