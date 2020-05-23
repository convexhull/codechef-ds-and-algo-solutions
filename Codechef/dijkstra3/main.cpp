#include<bits/stdc++.h>
using namespace std;
vector< vector< pair<int,int> > >graph(10010);
priority_queue< pair<int,int>, vector< pair<int,int> >, greater< pair<int,int> > >pq;
vector<int>dist(10010,987654);
vector<int>reach(10010);
int dijkstra(int st)
{
    dist[st]=0;
    reach[st]=1;
    pq.push(make_pair(dist[st],st));
    while(!pq.empty())
    {
        pair<int,int>top=pq.top();
        pq.pop();
        int v=top.second;
        int d=top.first;
        if(d<=dist[v])
        {
            for(vector< pair<int,int> >::iterator it=graph[v].begin();it!=graph[v].end();it++)
            {
                int v2=it->first;
                int cost=it->second;
                if(dist[v2]>dist[v]+cost)
                {
                    dist[v2]=dist[v]+cost;
                    pq.push(make_pair(dist[v2],v2));
                    reach[v2]=1;
                }
            }
        }
    }
    return 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        graph[a].push_back(make_pair(b,c));
        graph[b].push_back(make_pair(a,c));
    }
    int start;
    cin>>start;
    dijkstra(start);
    for(int i=1;i<=n;i++)
    {
        if(!reach[i])
            cout<<-1;
        else
            cout<<dist[i];
        cout<<" ";
    }
    return 0;
}
