


// Time complexity : O(V+E)
// Space complexity : O(V+E)


class Topological_DFS
{
    public :

    vector<ll> vis,sorted;
    stack<ll> stk;
    Topological_DFS(ll n , ll start_node , ll end_node, vector<vector<ll>> &edge)
    {
        vis.resize(n+1,0);
        for (ll i = start_node; i <= end_node; i++) 
        {
            if(vis[i] == 0) dfs(i,edge);
        }

        while(!stk.empty()) {sorted.push_back(stk.top()); stk.pop();}
    }

    void dfs( ll node , vector<vector<ll>>&edge )
        {
            vis[node] = 1;
            for(auto child : edge[node]) if(vis[child] == 0) dfs(child,edge);
            stk.push(node);
        }
};
