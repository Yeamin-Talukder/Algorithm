
//Time complexcity : O(V+E)

class BRIDGE
{
    public : 

    vector<ll> vis,discover_time,low_time;
    vector<pair<ll,ll>> bridge_edge;

    BRIDGE(ll n , vector<vector<ll>> &edge)
    {
        vis.resize(n+2);
        discover_time.resize(n+2);
        low_time.resize(n+2);

        ll discover_id = 1;

        for (ll i = 0; i <= n; i++)
        {
            if(vis[i] == 0) dfs(i,-1,discover_id,edge);
        }

    }

    void dfs(ll node , ll parent , ll &discover_id , vector<vector<ll>> &edge)
    {
        vis[node] = 1;
        discover_time[node] = discover_id;
        low_time[node] = discover_id;

        discover_id++;

        for(auto child : edge[node])
        {
            if(child == parent) continue;

            if(vis[child] == 1){ low_time[node] = min(low_time[node],low_time[child]); continue;}
            else dfs(child , node , discover_id , edge);
            
            low_time[node] = min(low_time[node],low_time[child]);
            if(discover_time[child] == low_time[child] ) bridge_edge.push_back({node,child});

        }

    }

};
