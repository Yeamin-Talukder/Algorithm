// Time Complexcity: 

// number_of_Divisors(n) – O(log n)

// Sum_of_Divisor(n) – O(log n * log e) due to power

// Euler_Totient(n) – O(log n)



// Just pass the Range value to the constructor when declaring the object
// and then the funtion will be work in that range 

class Prime_Factor
{
    public : 

    vector<ll> min_factor;

    Prime_Factor(ll range)
    {
        min_factor.resize(range);

        min_factor[1] = 1;
        for (ll i = 2; i < range; i++) // Here make min factor of all numbers
        {
            if(min_factor[i] == 0)
            {
                min_factor[i] = i;
                for (ll j = i * i; j < range; j+=i)
                {
                   if(min_factor[j] == 0) min_factor[j] = i;
                }
            }
        }

    }

      ll power(ll a, ll b) {
       ll result = 1;
       while (b > 0) {
           if (b & 1) result *= a;        
           a *= a;
           b >>= 1;              
       }
       return result;
   }

   unordered_map<ll,ll> get_factors(ll n)
   {
        unordered_map <ll,ll> factor;
        while(min_factor[n] != n )
        {
            factor[min_factor[n]]++;
            n /= min_factor[n];
        }
        if(n > 1) factor[n]++; 
        return factor;
   }


    ll Number_of_Divisors( ll n)  // Returns the number of divisors of n
    {
        unordered_map<ll,ll> factor = get_factors(n);
        ll ans = 1;
        for(auto u : factor) ans *= (u.second + 1); // Rule : (a + 1) * (b + 1).. 
        return ans;
    }


    ll Sum_of_Divisor( ll n)  // Returns the sum of divisors of n
    {
        unordered_map<ll,ll> factor = get_factors(n);
        ll ans = 1; 
        for(auto u : factor)
        {
            ans *= (power(u.first,u.second+1) - 1) / (u.first - 1); // Rule : (p^(a + 1) - 1) / (p - 1) * ...
        }
        return ans;
    }


    ll Euler_Totient (ll n ) // Number of co-prime (1 to n) Range with n
    {
        unordered_map<ll,ll> factor = get_factors(n);
        ll ans = n;
        for(auto u : factor) ans = (ans * (u.first - 1)) / u.first; // Rule : n * {(1 - 1/p) * (1 - 1/q) * ...}
        return ans;
    }

};
