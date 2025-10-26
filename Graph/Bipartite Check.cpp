class Bipartite
{
    public:

    vector<ll> save;
    ll not_bipartite = 0;
    
    Bipartite(vector<vector<ll>> &edge)
    {
        save.resize(edge.size()+5,-1);
        for(ll i = 0; i < edge.size(); i++) 
        {
          if(save[i] == -1)  dfs(i , 0 , edge);
        }
    }
    void dfs(ll node , ll color , vector<vector<ll>> &edge)
    {
        if(not_bipartite) return;
        save[node] = color;

        for(auto child : edge[node])
        {
            if(save[child] == -1) dfs(child , !color , edge );
            else if(save[child] == color) {not_bipartite = 1; return;}
        }
    }
};