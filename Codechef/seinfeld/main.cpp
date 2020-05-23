#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	while(1)
	{
	    static int i=1;
		string s;
		cin>>s;
		if(s[0]=='-')
			break;
		stack<char>mystack;
		for(int i=0;s[i]!='\0';i++)
		{
			if(s[i]=='{')
                mystack.push(s[i]);
            else if(!mystack.empty() && mystack.top()=='{')
                mystack.pop();
            else
                mystack.push(s[i]);
		}
        int cnt=0;
        for( ;!mystack.empty(); )
        {
            char a,b;
            a=mystack.top();
            mystack.pop();
            b=mystack.top();
            mystack.pop();
            if(a==b)
                cnt+=1;
            else
                cnt+=2;
        }
        cout<<i++<<". "<<cnt<<endl;
	}
	return 0;
}
