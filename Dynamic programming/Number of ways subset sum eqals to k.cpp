
vector<ll> v;
vector<ll> dp(target+1);
dp[0] = 1;

for (ll i = 0; i < v.size(); i++)
{
    for (ll j = target; j >= v[i]; j--)
    {
        dp[j] += dp[j-v[i]];
    }
}
