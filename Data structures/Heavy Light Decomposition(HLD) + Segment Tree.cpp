
class segment_tree
{

public : 

vector<ll>save,lazy;

segment_tree(ll size)
{
    save.resize(4*size);
    lazy.resize(4*size);
}

void create(ll node,ll start,ll end,vector<ll>&v)
{
if(start== end) {   save[node]=/*save_your_data_here*/;    return;}

ll mid = (start+end)/2;
create(node*2,start,mid,v);
create((node*2)+1,mid+1,end,v);

save[node]=/*save_your_data_here_when_geting_up*/; 
}

void update(ll node,ll start , ll end,ll l ,ll r,ll value)
{
if(start>r || end<l)return;

if(l<=start && end <=r)
{
    lazy[node]+=/*save_your_data_here*/;
    save[node]+=/*save_your_data_here*/;
    return;
}

ll mid = (start+end)/2;
update(node*2,start,mid,l,r,value);
update((node*2)+1,mid+1,end,l,r,value); 

save[node]=/*save_your_data_here_when_geting_up*/; 

}

void query(ll node,ll start , ll end,ll l,ll r,ll carry,ll &ans)
{

if(start>r || end<l)return;
if(l<=start && end<=r ){ans+=/*save_your_data_here*/;  return;}
ll mid=(start+end)/2;

query(node*2,start,mid,l,r,carry+lazy[node],ans);
query((node*2)+1,mid+1,end,l,r,carry+lazy[node],ans);

}


};



// create an object  of segment_tree like
// -> "segment_tree* segment = new segment_tree(n);" 
// -> "segment_tree segment(n);"  
//---- first one for pointer type and second one is normal way and n use for vector size declared

// -- declare create methode of the segment_tree first before use
// use node value 1 everywhere
// use 0 based index 
// use a ans variable for geting query ans in it




// Here edge is the tree edge and value is the value for each node in tree
class HLD
{
    public:

    vector<ll> depth,parent,heavy,head,pos,subtree_size , flat_tree;
    segment_tree  segment;


    HLD(vector<vector<ll>> &edge , vector<ll> &value ) : segment(edge.size())
    {
        depth.resize(edge.size());
        parent.resize(edge.size());
        heavy.resize(edge.size(),-1);
        head.resize(edge.size());
        pos.resize(edge.size());
        subtree_size.resize(edge.size(),1);
        flat_tree.resize(edge.size());

        dfs1(1,edge,0,1);
        ll count = 1;
        dfs2(1,edge , count , -1);

        for (ll i = 1; i < edge.size(); i++) flat_tree[pos[i]] = value[i-1];
        
        segment.create(1 , 1 , flat_tree.size()-1 , flat_tree);

    }

    void dfs1(ll node , vector<vector<ll>> &edge , ll height , ll par)
    {
        depth[node] = height;
        parent[node] = par;

        ll mx_subtree = 0;
        for(auto u : edge[node])
        {
            if(u == par) continue;
            dfs1(u,edge,height+1,node);

            subtree_size[node] += subtree_size[u];
            if(subtree_size[u] > mx_subtree) {mx_subtree = subtree_size[u]; heavy[node] = u;}
            
        }

    }

    void dfs2(ll node , vector<vector<ll>> &edge , ll &count , ll top )
    {
        if(top == -1) top = node; 
        head[node] = top;

        pos[node] = count++;
        if(heavy[node] == -1) return;

        dfs2(heavy[node] , edge , count , head[node]);
        for(auto u : edge[node]){
            if(u == heavy[node] || u == parent[node]) continue;
            dfs2(u,edge,count , -1);
        }

    }


    ll query_path(ll u , ll v )
    {
        ll ans = LLONG_MIN; // This Change based on the problem

        while(head[u] != head[v])
        {
            if(depth[head[u]] > depth[head[v]]){
                segment.query(1 , 1 , flat_tree.size()-1 , pos[head[u]] , pos[u] , 0 , ans);
                u = parent[head[u]];
            }
            else{
                segment.query(1 , 1 , flat_tree.size()-1 , pos[head[v]] , pos[v] , 0 , ans);
                v = parent[head[v]];
            }
        }

        segment.query(1 , 1 , flat_tree.size()-1 , min(pos[u],pos[v]) , max(pos[u],pos[v]) , 0 , ans);
        
        return ans;
    }


    void update_path(ll u , ll v , ll value)
    {
        segment.update(1 , 1 , flat_tree.size()-1 , pos[u] , pos[u] , value);
    }


}; // This is 1 based index HLD for each arry segment tree should also be 1 based index 
