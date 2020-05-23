#include<bits/stdc++.h>
using namespace std;
vector< vector< pair<int,int> > >graph(10010,vector< pair<int,int> >(10010));
set< pair<int,int> >s;
vector<int>dist(10010,numeric_limits<int>::max());
void dijkstra(int st)
{
    dist[st]=0;
    s.insert(make_pair(0,1));
    while(!s.empty())
    {
        pair<int,int>top=*s.begin();
        s.erase(s.begin());
        int v=top.second;
        int d=top.first;
        for(vector< pair<int,int> >::iterator it=graph[v].begin();it!=graph[v].end();it++)
        {
            int v2=it->first;
            int cost=it->second;
            if(dist[v2]>dist[v]+cost)
            {
                if(dist[v2]!=numeric_limits<int>::max());
                    s.erase(s.find(make_pair(dist[v2],v2)));
                dist[v2]=dist[v]+cost;
                s.insert(make_pair(dist[v2],v2));
            }
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

}
