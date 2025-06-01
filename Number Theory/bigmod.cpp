
// Time Complexity: O(log k)

  ll bigmod(ll a, ll b) {
        ll result = 1;
        while (b > 0) {
            if (b & 1) result = (result * a) % mod;        
            a = (a * a) % mod;
            b >>= 1;              
        }
        return result;
    }