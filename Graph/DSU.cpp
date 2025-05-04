
class dsu
{
    public: 

    vector<ll> parent,size;
    dsu(ll x){
        parent.resize(x+2);
        size.resize(x+2);
    }
    void make(ll x){
        parent[x] = x;
        size[x] = 1;
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

