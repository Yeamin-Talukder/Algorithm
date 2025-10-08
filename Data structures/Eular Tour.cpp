
// Time Complexity : O(N)
// Space Complexity : O(4*N)


// When use this with segment tree Remember
// For update you need to update in two position (in + out) in segment tree
 
class eular_tour
{
    public:

    vector<ll> in,out,flat_tree;

    eular_tour(vector<vector<ll>> &edge , vector<ll> &value)
    {
        in.resize(edge.size(),-1);
        out.resize(edge.size(),-1);
        flat_tree.resize(2*edge.size()-2);

        ll pos = 0;
        dfs(1 , edge , pos , -1);

        for(ll i = 1; i < edge.size(); i++) {
            flat_tree[in[i]] = value[i-1]; 
            flat_tree[out[i]] = value[i-1];
        }
    }

    void dfs(ll node , vector<vector<ll>> &edge , ll &pos , ll parent)
    {
        in[node] = pos++;
        for(auto child : edge[node]){
            if( child == parent) continue;
            dfs(child , edge , pos , node);
        }
        out[node] = pos++;
    }

};