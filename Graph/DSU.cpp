
// Time Complexity: 

// make(x)	O(1)
// find(x)	Amortized O(α(n)) (α = inverse Ackermann)
// merge(x, y)	Amortized O(α(n))

// α(n) is nearly constant, even for huge n (~10^9).



class dsu
{
    public: 

    vector<ll> parent,size;
    dsu(ll n){
        parent.resize(n+2);
        size.resize(n+2,1);
        for(ll i = 1 ; i <= n ; i++) parent[i] = i;
    }

    ll find(ll x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void merge(ll x , ll y)
    {
        ll a = find(x);
        ll b = find(y);

        if(a != b)
        {
            if(size[a] > size[b]) swap(a,b);
            parent[a] = b;
            size[b] += size[a];
        }

    }

};

// dsu dsu(n); // this declare the dsu class 

