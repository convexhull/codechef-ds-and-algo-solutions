#include<bits/stdc++.h>
using namespace std;
void cpp(string &s)
{
    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]>=65 && s[i]<=90)
        {
            cout<<"Error!";
            return;
        }
    }
    for(int i=1;s[i+1]!='\0';i++)
    {
    	if(s[i]=='_' && s[i+1]=='_')
    	{
    		cout<<"Error!";
    		return;
    	}
    }
    for(int i=1;s[i+1]!='\0';i++)
    {
        if(s[i]=='_')
        {
            s[i]=-1;
            if( s[i+1]>=97 && s[i+1]<=122)
            {
            	s[i+1]=s[i+1]-32;
            }
        }
    }
    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]!=-1)
            cout<<s[i];
    }
}
void java(string &s)
{
    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]>=65 && s[i]<=90)
            cout<<"_"<<(char)(s[i]+32);
        else
            cout<<s[i];
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    while(cin>>s)
    {
        int l=s.length();
        if(!(s[0]>=97&&s[0]<=122))
        {
            cout<<"Error!"<<endl;
            continue;
        }
        if(s[l-1]=='_')
        {
            cout<<"Error!"<<endl;
            continue;
        }
        int x=0;
        for(int i=0;s[i]!='\0';i++)
        {
            if(s[i]=='_')
            {
                x=1;
                break;
            }
        }
        if(x==1)
            cpp(s);
        else
            java(s);
    cout<<endl;
    }
    return 0;
}
