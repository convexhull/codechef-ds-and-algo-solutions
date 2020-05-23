#include<bits/stdc++.h>
using namespace std;
vector< vector< pair<int,int> > >graph(3010);
set< pair<int,int> >s;
vector<int>dist(3010,numeric_limits<int>::max());
void dijkstra(int start)
{
    dist[start]=0;
    s.insert(make_pair(dist[start],start));
    while(!s.empty())
    {
        pair<int,int>p=*s.begin();
        int v=p.second;
        s.erase(s.begin());
        for(vector< pair<int,int> >::iterator it=graph[v].begin();it!=graph[v].end();it++)
        {
            int vertex=it->first;
            int weight=it->second;
            if(dist[vertex]>dist[v]+weight)
            {
                if(dist[vertex]!=numeric_limits<int>::max())
                {
                    s.erase(s.find(make_pair(dist[vertex],vertex)));
                }
                dist[vertex]=dist[v]+weight;
                s.insert(make_pair(dist[vertex],vertex));
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        graph[a].push_back(make_pair(b,c));
        graph[b].push_back(make_pair(a,c));
    }
    int s;
    cin>>s;
    dijkstra(s);
    for(int i=1;i<=n;i++)
    {
        if(i!=s)
        {
            if(dist[i]!=numeric_limits<int>::max())
                cout<<dist[i];
            else cout<<-1;
            cout<<" ";
        }
    }

    cout<<endl;
    }
    return 0;
}
