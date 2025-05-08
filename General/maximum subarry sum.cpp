
// Time Complexity: O(n)


// just provide the vector where need to work
ll max_subarry_sum(vector<ll> &v )
{
    ll sum = 0;
    ll mx = LLONG_MIN;
    
    for (ll i = 0; i < v.size(); i++)
    {
        sum += v[i];
        mx = max(mx,sum);
        if(sum < 0) sum = 0;
    }
    
    return mx;

}
