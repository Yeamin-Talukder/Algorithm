
// Time Complexity: 

// Constructor : O(nlogn)
// dfs  :        O(n)
// k_ancestor :  O(logk)
// LCA :         O(logn) 
// Distance :    O(logn)

// Space Complexity: O(nlogn)



class Binary_lifting
{
    public : 

    vector<vector<ll>> up;
    vector<ll> depth;

    Binary_lifting(ll n , vector<vector<ll>> &edge)
    {
        up.resize(n+1,vector<ll>(20,-1));
        depth.resize(n+1,0);

        dfs(1,-1,edge); // Here we create initial parent and depth of each node from node : 1

        for (ll i = 1; i < 20; i++) // This make the Binary lifting table
        {
            for (ll j = 1; j <= n; j++)
            {   
                if(up[j][i-1] != -1) up[j][i] = up[ up[j][i-1] ] [i-1]; // 2^i th parent of j
            } 
        }

    }

    void dfs(ll node , ll parent , vector<vector<ll>> &edge)
    {
        up[node][0] = parent;
        if(parent != -1) depth[node] = depth[parent] + 1;

        for(auto child:edge[node])
        {
            if(child != parent) dfs(child,node,edge);
        }
    }

    ll k_ancestor(ll node , ll k)
    {
        while( k != 0)
        {
            ll x = log2(k);
            node = up[node][x];
            k -= (1LL << x);

            if(node == -1 ) return -1; // If there is no k_ancestor
        }
        return node;
    }


    ll lca(ll a , ll b)
    {   
        if(depth[a] < depth[b]) swap(a,b);
        ll diff = depth[a] - depth[b];
        a = k_ancestor(a,diff); // This make a and b at same level

        if(a == b) return a; // If one node is ancestor of other node

        for (ll i = 19; i >= 0 ; i--) // This loop take nodes to the place where they are not matching
        {
            if(up[a][i] != -1 && up[a][i] != up[b][i])
            {
                a = up[a][i];
                b = up[b][i];
            }
        }

        return up[a][0]; // Return the initial parent of a or b which is lca of a and b
    }


    ll distance(ll a , ll b)
    {
        return depth[a] + depth[b] - (2 * depth[lca(a,b)]); // This give the distance between a and b
    }



};


// Declaration of Binary_lifting class : Binary_lifting lift(n,edges); 