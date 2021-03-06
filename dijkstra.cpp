#include<bits/stdc++.h>
using namespace std;

const int inf=1e7;

int main()
{
    int n,m; // n=vertex,m=edges
    cin>>n>>m;
    vector<int>dist(n+1,inf);
    vector<vector<pair<int,int>>>graph(n+1);
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w}); // remove this line in case of directed graph
    }
    int source;
    cin>>source;
    dist[source]=0;
    set<pair<int,int>>s;
    //{weight,vertex}
    s.insert({0,source});
    while(!s.empty())
    {
        auto x=*(s.begin());
        s.erase(x);
        for(auto it:graph[x.second])
        {
            if(dist[it.first]>dist[x.second]+it.second)
            {
                s.erase({dist[it.first],it.first});
                dist[it.first]=dist[x.second]+it.second;
                s.insert({dist[it.first],it.first});
            }
        }
    }
    /* printing final output
    output contain dist from source to all distination
    like 0 -> 1
         0 -> 2
         0 -> 3.....etc
    */
     for(int i=1;i<=n;i++)
     {
         if(dist[i]<inf)
         {
             cout<<dist[i]<<" ";
         }
         else
         {
             cout<<-1<<" ";
         }
     }
    return 0;
}

/*
sample input:-

5 6
1 2 4
2 3 2
3 1 1
2 5 4
3 4 4
4 5 4
1    

Output:-

0 3 1 5 7

*/