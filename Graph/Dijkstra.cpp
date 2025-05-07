

// Time complexity : O( (n + m) * log n)


// Single-source shortest path algorithm with positive weights using priority queue
class Dijkstra
{
public:

    vector<ll> dis;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

    Dijkstra(ll n, ll root, vector<vector<pair<ll, ll>>> &adj)
    {
        dis.resize(n + 1, LLONG_MAX);
        pq.push({0, root});
        dis[root] = 0;

        while (!pq.empty())
        {
            ll node = pq.top().second;
            ll distance = pq.top().first;

            pq.pop();

            if (distance > dis[node]) continue;

            for (auto u : adj[node])
            {
                if (distance + u.first < dis[u.second])
                {
                    dis[u.second] = distance + u.first;
                    pq.push({dis[u.second], u.second});
                }
            }
        }
    }
};


// Just give the value of constructor 
//and it will give you the shortest path from root to all the nodes

// Dijkstra path(n,1,adj);
// just declare like this 

