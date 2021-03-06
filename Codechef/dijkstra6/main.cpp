#include<bits/stdc++.h>
#define INF 99999999

#define pb push_back

#define mp make_pair

using namespace std;

vector<pair<int,int> >adj[10009];

vector<int> dijkstra(vector<int>d,int s,int n)

{

d.clear();

d.resize(n+1);
for(int i=0;i<=n;i++)
d[i]=INF;
set<pair<int,int> >q;
q.clear();
bool vis[n+2];
memset(vis,false,sizeof(vis));
vis[s]=true;
d[s]=0;
q.insert(mp(0,s));
while(!q.empty())
{
    pair<int,int> top = *q.begin();
    q.erase(q.begin());
    int u=top.second;
    vector<pair<int,int> >::iterator it;
    for(it=adj[u].begin();it!=adj[u].end();it++)
    {
        int v=it->second;
        int cost=it->first;
        if(d[v]>d[u]+cost)
        {
            if(d[v]!=INF)
            {
                q.erase(q.find(mp(d[v],v)));
            }
            d[v]=d[u]+cost;
            q.insert(mp(d[v],v));
        }

    }
}
return d;
}

int main()

{

int T,r,x,y,n,m,i,s,d;

cin>>T;
while(T--)
{
    cin>>n>>m;
    for(i=0;i<=n+9;i++)
    adj[i].clear();
    vector<int>d1;
    d1.resize(n+1);
    for(i=0;i<m;i++)
    {
        cin>>x>>y>>r;
        adj[x].pb(mp(r,y));
        adj[y].pb(mp(r,x));
    }
    cin>>s;
    d1=dijkstra(d1,s,n);
    for(i=1;i<=n;i++)
    {
        if(i!=s)
        {
            if(d1[i]!=INF)
            cout<<d1[i]<<" ";
            else
            cout<<"-1 ";
        }

    }
    cout<<endl;
}
return 0;
}
