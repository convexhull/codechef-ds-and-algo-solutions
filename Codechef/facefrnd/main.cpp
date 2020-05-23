#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    set<string>myset;
    for(int i=1;i<=n;i++)
    {
        string str;
        cin>>str;
        myset.insert(str);
        int m;
        cin>>m;
        for(int j=1;j<=m;j++)
        {
            string s;
            cin>>s;
            myset.insert(s);
        }
    }
    cout<<(int)myset.size()-n<<endl;
    return 0;
}
