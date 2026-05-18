
// Forward loop for Unbounded knapsack
// backward loop for 0/1 knapsack


// Time Complexcity : O(n * target)

ll inf = 1e18;
ll unbounded_knapsack(ll target , vector<ll> &value , vector<ll> &cost)
{
    vector<ll> dp(target+1 , inf);
    dp[0] = 0;

    for (ll i = 0; i < value.size(); i++)
    {
        ll val = value[i];
        ll cos = cost[i];

        for (ll j = val; j <= target; j++)
        {
            dp[j] = min(dp[j] , dp[j-val] + cos);
        }
    }

    return dp[target];
}

