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
        int n,k;
        bool flag1,flag2;
        flag1=flag2=false;
        cin>>n>>k;
        set<int>s;
        for(int i=1;i<=n;i++)
        {
            int x;
            cin>>x;
            for(int l=1;l<=x;l++)
            {
                int a;
                cin>>a;
                s.insert(a);
            }
            if(i==n-1)
            {
                if(s.size()!=k)
                    flag1=true;
            }
            if(i==n&&flag1==true)
            {
                if(s.size()==k)
                    flag2=true;
            }
        }
        if(s.size()!=k)
        {
            cout<<"sad"<<endl;
        }
        else
        {
            if(flag2)
                cout<<"all"<<endl;
            else
                cout<<"some"<<endl;
        }
    }
    return 0;
}
