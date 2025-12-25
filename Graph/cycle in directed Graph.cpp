

class cycle
{
    public : 

    vector<ll> vis;
    ll loop = 0;

    cycle(ll n , vector<vector<ll>> &adj)
    {
        vis.resize(n+1);
        for (ll i = 0; i <= n; i++)
        {
            if(vis[i] == 0) dfs( i , adj);
        }
    }

    void dfs(ll node , vector<vector<ll>> &adj)
    {
        if(vis[node] == 1){ loop = 1; return; }

        vis[node] = 1;

        for(auto child : adj[node])
        {
            if(vis[child] != 2) dfs(child , adj);
            if(loop == 1) return;
        }

        vis[node] = 2;
    }

};