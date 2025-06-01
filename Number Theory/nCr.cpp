// Time Complexcity: O(n)

// This calculates nCr useing Fermat's Little Theorem with modular inverse technique.

class ncr
{
    public : 

    vector<ll> factorial;
    ll mod = 1e9 + 7;

    ncr( ll size)
    {
        factorial.resize(size + 1);
        factorial[0] = 1;

        ll val = 1;
        for (ll i = 1; i <= size; i++)
        {
            val = (val * i) % mod;
            factorial[i] = val;
        }
    }

      ll bigmod(ll a, ll b) {
            ll result = 1;
            while (b > 0) {
                if (b & 1) result = (result * a) % mod;        
                a = (a * a) % mod;
                b >>= 1;              
            }
            return result;
        }

    ll cal( ll n , ll r)
    {
        ll a = factorial[n];
        ll b = (factorial[r] * factorial[n - r]) % mod;
        return ( a * bigmod(b , mod - 2) ) % mod;
    }
};
