
// Time Complexity : O(n^3)
// Space Complexity : O(n^2)

// Declaration : Floyd_Warshall f(n); then take all given edge values then call run funtion 
// Run : f.run(n);

class Floyd_Warshall
{
    public : 

    vector<vector<ll>> dis;
    
    Floyd_Warshall(ll n )
    {
        dis.resize(n+2 , vector<ll>(n+2, LLONG_MAX));
        for(ll i = 1; i <= n; i++) dis[i][i] = 0;
    }

    void run(ll n )
    {
        for (ll k = 1; k <= n; k++)
        {
            for (ll i = 1; i <= n; i++)
            {
                for(ll j = 1; j <= n; j++)
                {
                    if(dis[i][k] == LLONG_MAX || dis[k][j] == LLONG_MAX) continue;
                    dis[i][j] = min(dis[i][j] , dis[i][k] + dis[k][j]);
                }
            }
        }
    }

};