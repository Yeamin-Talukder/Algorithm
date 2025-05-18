

// Time complexcity :  O(n + m log m)

// Found the number of SCC
// Unique SCC Id for each node
// Make DAG with SCC 



class SCC
{
    public :

    vector<ll> vis;
    stack<ll> finished;
    vector<vector<ll>> reverse_edge;
    ll number_of_scc = 0;
    vector<ll> scc_id;
    vector<vector<ll>> scc_graph;

    SCC( ll n , ll start_node , ll end_node, vector<vector<ll>> &edge )
    {
        vis.resize(n+1);                       
        reverse_edge.resize(n+1);                       
        scc_id.resize(n+1);                       

        for (ll i = start_node; i <= end_node; i++)
        {
            if(vis[i] == 0) dfs(i , 1 , edge , 1); // store node by finished time order
        }

        reverse_path(edge); // This reverse the edge and store in reverse_edge

        vis.assign(n+1,0); // reset the vis 
        ll id = 1; 
        while(!finished.empty())
        {
            ll node = finished.top(); finished.pop();
            if(vis[node] == 0) 
            {
                number_of_scc++; // Count the number of SCC in graph
                dfs(node , id++ , reverse_edge , 2 ); // store node by scc id in scc_id
            }
        }

        scc_graph.resize(number_of_scc+1); // Declare the size of scc_graph with Number of SCC
        made_scc_graph(edge); // This make DAG of SCC and store in scc_graph


    }
    
    void dfs(ll node , ll id ,  vector<vector<ll>> &edge , ll type)
    {
        vis[node] = id;
        if(type == 2) scc_id[node] = id;

        for(auto child : edge[node]) 
        {
            if(vis[child] == 0) dfs(child , id , edge , type);
        }

        if(type == 1 ) finished.push(node); // This store the last finished node in the stack top
    }

    void reverse_path(vector<vector<ll>> &edge)
    {
        for (ll i = 0; i < edge.size(); i++)
        {
            for(auto child : edge[i]) reverse_edge[child].push_back(i);
        }
    }

    void made_scc_graph(vector<vector<ll>> &edge)
    {
        map<pair<ll,ll> , ll > check;

        for (ll i = 1; i < edge.size(); i++)
        {
            for(auto child : edge[i])
            {
                if(scc_id[i] != scc_id[child] && check[{scc_id[i] , scc_id[child]}] == 0)
                {
                    check[{scc_id[i],scc_id[child]}] = 1;
                    scc_graph[scc_id[i]].push_back(scc_id[child]);
                }
            }
        }

    }


};