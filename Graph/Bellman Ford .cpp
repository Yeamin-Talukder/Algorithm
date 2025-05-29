

// Time Complexity: O(V * E)


class Bellman_ford
{
    public : 

    vector<ll> dis;
    bool found_negative_cycle = false;

    Bellman_ford(ll n , ll source , vector<tuple<ll,ll,ll>> &edge)
    {
    dis.resize(n + 1 , LLONG_MAX);
    dis[source] = 0; 

        for (ll i = 1; i <= n; i++)
        {
           found_negative_cycle |= relax(edge , i , n);
        }
    }

    bool relax(vector<tuple<ll , ll , ll>> &edge , ll iteration , ll n)
    {
        for(auto [weight , u , v] : edge)
        {
            if(dis[u] != LLONG_MAX && dis[u] + weight < dis[v])
            {
                if(iteration == n) return true;
                dis[v] = dis[u] + weight;
            }
        }
        return false; 
    }

};
