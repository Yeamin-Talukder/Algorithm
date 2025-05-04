// this convert string into a ll hash value in O(n)
// here you need to declare prime and mod value for use
ll get_hash(string &s)
{
    ll val = 0;
    for (ll i = 0; i < s.size(); i++)
    {
    val = ( (val * prime) + (ll)s[i] ) % mod;
    }
    return val;
}
 