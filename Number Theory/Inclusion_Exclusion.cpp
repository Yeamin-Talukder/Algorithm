
// Time Complexity : 
// Recursive Approach : O(2^n)      || Space Complexity : O(n)
// Iterative Approach : O(2^n * n)  || Space Complexity : O(1)


// Recursive Approach ( very Fast Because of pruning method)
void Inclusion_Exclusion(ll n , vector<ll> &v , ll index ,ll size , ll lcm , ll &ans)
{
    if(index == v.size())
    {
        if(size == 0) return;
        if(size % 2 == 0) ans -= (n/lcm);
        else ans += (n/lcm);
        return;
    }

    Inclusion_Exclusion(n , v , index+1 , size , lcm , ans);

    ll x = (lcm * v[index]) / __gcd(lcm , v[index]);
    if(x <= n) Inclusion_Exclusion(n , v , index+1 , size+1 , x , ans );
}


// Iterative Approach Bitmask (very Slow Compared to Recursive Approach)
ll Inclusion_Exclusion(ll n , vector<ll> &v )
    {
        ll ans = 0;
        for (ll i = 1; i < (1LL << v.size()); i++)
        {
            ll count = 0;
            ll lcm = 1;

            for (ll j = 0; j < v.size(); j++)
            {
                if( i & (1 << j) )
                {
                    count++; lcm = (lcm * v[j] ) / __gcd(lcm , v[j]);
                    if(lcm > n) break;
                }
            }            
            if(lcm <= n) ((count % 2 == 0)? ans -= n/lcm : ans += n/lcm);
        }

        return ans;
    }