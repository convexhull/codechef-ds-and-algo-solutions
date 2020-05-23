#include<bits/stdc++.h>
using namespace std;
int main()
{
    while(1)
    {
        int b,n;
        cin>>b>>n;
        if(b==0&&n==0)
            break;
        vector< pair<int,int> >v(n+1);
        for(int i=1;i<=n;i++)
        {
            int a,b;
            cin>>a>>b;
            v[i].first=a;
            v[i].second=b;
        }
        vector< vector<int> >matrix(n+1,vector<int>(b+1,0));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=b;j++)
            {
                int val=0;
                if(v[i].first<=j)
                    val=matrix[i-1][j-v[i].first]+v[i].second;
                matrix[i][j]=max(val,matrix[i-1][j]);
            }
        }
        int p=numeric_limits<int>::max();
        for(int i=b;i>=0;i--)
        {
            if(matrix[n][i]==matrix[n][b])
                p=i;
        }
        cout<<p<<" "<<matrix[n][b]<<endl;
    }
    return 0;
}
