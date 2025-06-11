
// Time Complexity :
// modulo()	O(N)
// sum()	O(max(N, M))
// mul_si()	O(N)


class String_Arithmetic
{
    public : 

ll modulo(string a , ll b)
    {
        ll val = 0;
        for(auto c:a)
        {
            if( c == '-') continue;
            val = (val * 10 + (c - '0')) % b;
        }
        return val;
    }


     void sum(string &a , string &b)
     {
        if(a.size() < b.size())  swap(a,b);
        ll carry = 0;
        ll n = a.size() , m = b.size();

        for (ll i = 0; i < n; i++)
        {
            ll x = (a[n-1-i] - '0');
            ll y = (i < m)? (b[m - 1 - i] - '0') : 0;
            x = x + y + carry;
            a[n-1-i] = (x % 10) + '0';
            carry = x / 10;
        }
        if(carry > 0) a = to_string(carry) + a;
     }

     void mul_si(string &a , ll b)
     {
        ll carry = 0;
        ll n = a.size();

        for (ll i = n-1; i >= 0 ; i--)
        {
            ll x = (b * (a[i] - '0')) + carry;
            a[i] = (x % 10) + '0';
            carry = x / 10;
        }
        if(carry > 0) a = to_string(carry) + a;
     }

}; 
