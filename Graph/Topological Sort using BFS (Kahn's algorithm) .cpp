

// Time complexity : O(V+E)
// Space complexity : O(V+E)


class Topological_BFS
{
    public : 

    vector<ll> sorted;
    queue<ll> zero_inorder;
    Topological_BFS ( ll n , ll start_node , ll end_node , vector<vector<ll>> &edge , vector<ll> &inorder) // inorder in the number of edge directed to a node
    {
        for (ll i = start_node; i <= end_node ; i++) 
        {
            if(inorder[i] == 0) zero_inorder.push(i);
        }

        while(!zero_inorder.empty())
        {
            ll node = zero_inorder.front(); 
            zero_inorder.pop();
            sorted.push_back(node);

            for(auto child : edge[node]) 
            {
                inorder[child]--;
                if(inorder[child] == 0) zero_inorder.push(child);
            }
        }

    }


};

