
// Bell Number
// Stirling Number Give us Number of ways we can group/split n numbers  into k groups
class Bell // Number of way we can group/split n numbers of elements
{
    public : 
    vector<vector<ll>> s; // Stirling Number
    ll mod = 1e9+7;

    Bell( ll range )
    {
        s.resize(range , vector<ll>(range , -1));
    }

    ll stirling( ll n , ll k) // Rule : s(n,k) = k * s(n-1,k) + s(n-1,k-1)
    {
        if(n == k || k == 1) return 1;
        if(n == 0 || k <= 0 || k > n ) return 0;

        if(s[n][k] != -1) return s[n][k];
        return s[n][k] = ( ( k * stirling(n-1 , k) ) % mod + stirling(n-1 , k-1)) % mod;
    }

    ll cal( ll n ) // This calculate Bell Number || Rule : sum of all Stirling Number (1 to n)
    {
        ll ans = 0;
        for (ll i = 1; i <= n; i++) ans = (ans + stirling(n , i)) % mod;
        return ans;
    }
};



// Fubini Number || Ordered Bell Number
// This Also make group/split of n elements + Rank Each Group All possible ways (No Two Group Can tie) 
class Fubini 
{
    public :

    vector<vector<ll>> s; // Stirling Number
    vector<ll> factorial;
    ll mod = 1e9+7;

    Fubini(ll range)
    {
        s.resize(range+2 , vector<ll>(range+2 , -1));
        factorial.resize(range+2 , 1);

        for (ll i = 1; i < range+1; i++)
        {
            factorial[i] = (factorial[i-1] * i) % mod;
        }

    }

    ll stirling( ll n , ll k) // Rule : s(n,k) = k * s(n-1,k) + s(n-1,k-1)
    {
        if(n == k || k == 1) return 1;
        if(n == 0 || k <= 0 || k > n ) return 0;

        if(s[n][k] != -1) return s[n][k];
        return s[n][k] = ( ( k * stirling(n-1 , k) ) % mod + stirling(n-1 , k-1)) % mod;
    }


    // Here we take k! Because of each group Ranking(permutation) 
    ll cal( ll n) // Rule : Sum of All (Stirling Nuber * k!) in (1 to n) 
    {
        ll ans = 0;
        
        for (ll i = 1; i <= n; i++)
        {
            ans = (ans + (stirling(n,i) * factorial[i]) % mod ) % mod;
        }

        return ans;
    }

};
