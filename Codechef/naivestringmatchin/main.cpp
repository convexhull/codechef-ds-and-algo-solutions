#include<bits/stdc++.h>
using namespace std;
void match(string &text, string &pat)
{
    int l=pat.length();
    for(int i=0;text[i]!='\0';i++)
    {
        int j;
        for(j=0;j<=l-1;j++)
        {
            if(text[i+j]!=pat[j])
                break;
        }
        if(j==l)
            cout<<i<<" ";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        string text,pat;
        cin>>text>>pat;
        match(text,pat);
        cout<<endl;
    }
    return 0;
}
