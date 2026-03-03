

// 2D dp solution of 0/1 Knapsack.
// Time Complexcity : O(n*w)
// Space Complexcity : O(n*w)


vector<vector<ll>> dp; // declare the size of dp vector
ll Knapsack (ll  index , ll left_w , vector<pair<ll,ll>> &v)
{
    if(index == v.size() || left_w <= 0) return 0;
    if(dp[index][left_w] != -1) return dp[index][left_w];

    ll ans = Knapsack(index+1 , left_w , v);
    if(left_w - v[index].first  >= 0 ) ans = max(ans , Knapsack(index+1 , left_w - v[index].first , v ) + v[index].second );

    return dp[index][left_w] =  ans;
}




// 1D dp solution of 0/1 Knapsack.

// Time Complexcity : O(n * weight) 
// Space Complexcity : O(weight)

    vector<ll> dp(weight + 1, 0);

    for (ll i = 0; i < n; i++) {
        ll wt = v[i].first;
        ll val = v[i].second;

        for (ll w = weight; w >= wt; w--) {
            dp[w] = max(dp[w], dp[w - wt] + val);
        }
    }