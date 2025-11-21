
class max_bipartite_matching
{
public:

vector<ll> left,right;
vector<ll> pairU,pairV,dis;
vector<vector<ll>> edge;
ll n,m;

max_bipartite_matching(vector<vector<ll>> &edge , ll n , ll m) : edge(edge),n(n),m(m)
{
    pairU.resize(n+1);
    pairV.resize(m+1);
    dis.resize(n+1);
}

bool bfs()
{
    ll found_augmenting_path = false;
    queue<ll> q;

    for (ll i = 1; i <= n; i++)
    {
        if(pairU[i] == 0)
        {
            dis[i] = 0; 
            q.push(i);
        }
        else dis[i] = LLONG_MAX;
    }

    while(!q.empty())
    {
        ll u = q.front(); q.pop();

        for(auto child : edge[u])
        {
            ll match_u = pairV[child];

            if(match_u == 0)
            {
                found_augmenting_path = true;
            }
            else if(dis[match_u] == LLONG_MAX)
            {
                dis[match_u] = dis[u] + 1;
                q.push(match_u);
            }
        }
    }

    return found_augmenting_path;

}

bool dfs(ll node)
{
    for(auto child : edge[node])
    {
        ll match_u = pairV[child];

        if(match_u == 0 || (dis[match_u] == dis[node] + 1 && dfs(match_u)))
        {
            pairU[node] = child;
            pairV[child] = node;
            return true;
        }
    }

    dis[node] = LLONG_MAX;
    return false;
}

ll max_matching()
{
    ll matching = 0;

    while(bfs())
    {
        for (ll i = 1; i <= n ; i++)
        {
            if(pairU[i] == 0 && dfs(i) ) matching++;
        }
    }

    return matching;
}


};