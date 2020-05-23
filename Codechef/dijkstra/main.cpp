#include<bits/stdc++.h>
using namespace std;
vector<int>dist(10010,numeric_limits<int>::max());
vector<int>vis(10010);
priority_queue< pair<int,int>,vector< pair<int,int> >,greater< pair<int,int> > >pq;
vector< vector< pair<int,int> > >graph(10010,vector< pair<int,int> >(10010));
void dijkstra()
{
    pair<int,int>p=make_pair(0,1);
    pq.push(p);
    //vis[1]=1;
    while(!pq.empty())
    {
        pair<int,int>top=pq.top();
        pq.pop();
        int ver=top.second;
        int d=top.first;
        if(vis[ver])
            continue;
        vis[ver]=1;
        for(int i=0;i<=graph[ver].size()-1;i++)
        {
            int wei=graph[ver][i].first;
            int vert=graph[ver][i].second;
            if(dist[vert]>dist[ver]+wei)
                dist[vert]=dist[ver]+wei;
            pair<int,int>p1=make_pair(dist[vert],vert);
            pq.push(p1);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    dist[1]=0;
    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        pair<int,int>p1=make_pair(c,b);
        graph[a].push_back(p1);
        pair<int,int>p2=make_pair(c,a);
        graph[b].push_back(p2);
    }
    dijkstra();
    for(int i=1;i<=n;i++)
    {
        cout<<dist[i]<<" ";
    }
    return 0;
}
