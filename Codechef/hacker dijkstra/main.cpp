#include<bits/stdc++.h>
using namespace std;
vector< vector< pair<long long,long long> > >graph(10010);
priority_queue< pair<long long,long long>, vector< pair<long long,long long> >, greater< pair<long long,long long> > >pq;
vector<long long>dist(10010,numeric_limits<long long>::max());
vector<long long>reach(10010);
long long dijkstra(long long st)
{
    dist[st]=0;
    reach[st]=1;
    pq.push(make_pair(dist[st],st));
    while(!pq.empty())
    {
        pair<long long,long long>top=pq.top();
        pq.pop();
        long long v=top.second;
        long long d=top.first;
        if(d<=dist[v])
        {
            for(vector< pair<long long,long long> >::iterator it=graph[v].begin();it!=graph[v].end();it++)
            {
                long long v2=it->first;
                long long cost=it->second;
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
    long long T;
    //cin>>T;
    //while(T--)
      //  {
        long long n,m;
    cin>>n>>m;
    for(long long i=1;i<=m;i++)
    {
        long long a,b,c;
        cin>>a>>b>>c;
        graph[a].push_back(make_pair(b,c));
        graph[b].push_back(make_pair(a,c));
    }
    long long start;
    cin>>start;
    dijkstra(start);
    for(long long i=1;i<=n;i++)
    {
        if(i==start)
            continue;
       cout<<dist[i]<<" ";
    }

    return 0;
}
