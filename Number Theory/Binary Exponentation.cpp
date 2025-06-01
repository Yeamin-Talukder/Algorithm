
// Time Complexity: O(log b)

ll power(ll a, ll b) {
    ll result = 1;
    while (b > 0) {
        if (b & 1) result *= a;        
        a *= a;
        b >>= 1;              
    }
    return result;
}
