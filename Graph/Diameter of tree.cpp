

// Time complexity: O(n)
// Space complexity: O(n)


// This is the Single DFS method (Faster than the double DFS method)

class Diameter
{
    public : 

    ll ans = 0;
    vector<ll> save;

    Diameter(ll n , vector<vector<pair<ll,ll>>> &adj)
    {
        save.resize(n+1);
        dfs(0,-1,adj);
    }

ll dfs(ll node, ll parent, vector<vector<pair<ll,ll>>> &adj)
{
    vector<ll> mx;
    for(auto u:adj[node])
    {
        if(u.second != parent)
        {   
            ll x = dfs(u.second,node,adj);
            save[node] = max(save[node],x+u.first); 
            mx.push_back(x+u.first);
        }
    }

    sort(mx.rbegin(),mx.rend());
    ll x = (mx.size() > 0 ?  mx[0]:0) + (mx.size() > 1 ? mx[1] : 0) ;
    ans = max(ans,x);

    return save[node];
}

};





// This is the double DFS method

class Diameter
{
public:
    ll ans = 0;
    ll farthestNode = 0;
    vector<vector<pair<ll, ll>>> &adj;

    Diameter(ll n, vector<vector<pair<ll, ll>>> &graph) : adj(graph)
    {
        dfs(0, -1, 0); // first DFS from any node
        ans = 0;
        dfs(farthestNode, -1, 0); // second DFS from farthest node found
    }

    void dfs(ll node, ll parent, ll distance)
    {
        if (distance > ans)
        {
            ans = distance;
            farthestNode = node;
        }

        for (auto &u : adj[node])
        {
            if (u.first != parent) dfs(u.first, node, distance + u.second);
        }
    }
};