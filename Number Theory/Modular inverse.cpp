
// Time Complexity: O(log n)


// Modular Inverse using Fermat's Little Theorem

// In the mod_value you need to pass a prime number.
// Before using you need to make sure that prime and the value a is coprime.


class Modular_Inverse
{
    public : 

    ll mod;

    Modular_Inverse(ll mod_value)
    {
        mod = mod_value;
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

        ll cal ( ll a)
        {
            return bigmod(a, mod - 2);
        }
};