


class tree_centroid
{
    public:

    vector<ll> subtree_size;
    vector<ll> mx_child;
    ll centroid = 1; // set centroid to root value 
    tree_centroid(ll n , vector<vector<ll>> &edge )
    {
        if(n == 1) return;
        subtree_size.resize(edge.size(),1);
        mx_child.resize(edge.size());

        dfs(1,-1,edge);

        centroid = 1; // set centroid to root value
        ll mx_size = n/2;

        while(1)
        {
            if( subtree_size[ mx_child[centroid]] > mx_size) centroid = mx_child[centroid];
            else break;
        }

    }

    void dfs( ll node , ll parent , vector<vector<ll>> &edge) // This save the subarry size for each node
    {
        ll mx = 0;
        for(auto child : edge[node])
        {
            if(child == parent) continue;
            dfs(child , node , edge);
            subtree_size[node] += subtree_size[child];

            if(mx < subtree_size[child]) {
                mx_child[node] = child; 
                mx = subtree_size[child];
            } 
        }
    }


};