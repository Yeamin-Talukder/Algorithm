
// single source shortest path algo with positive weights
class Dijkstra
{

public : 

vector<ll> vis,dis;
set<pair<ll,ll>> srt_path;
Dijkstra(ll n , ll root ,vector<vector<pair<ll,ll>>> &adj)
{
    vis.resize(n+1,0);
    dis.resize(n+1,LLONG_MAX);
    srt_path.insert({0,root});
    dis[root] = 0;

    while (srt_path.size() != 0)
    {
        ll node = srt_path.begin()->second;
        ll distance = srt_path.begin()->first;

        srt_path.erase(srt_path.begin());
        
        if(vis[node] == 1) continue;
        vis[node] = 1;

        for(auto u:adj[node])
        {
            if( distance + u.first <  dis[u.second]  )
            {
                dis[u.second] = distance + u.first;
                srt_path.insert({dis[u.second],u.second});
            }
        }

    }
    
}

};

// Just give the value of constructor 
//and it will give you the shortest path from root to all the nodes

// Dijkstra path(n,1,adj);
// just declare like this 

