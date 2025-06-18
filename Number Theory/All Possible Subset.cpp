  
  // Time Complexity : O(2^n * n(for printing))
  
  // Recursive Approach
  void subset(vector<ll>&v , vector<ll> &result , ll index )
    {
        if(index == v.size()) 
        {
            for(auto u:result) cout<<u<< " " ;
            cout << endl;
            return;
        }

        subset( v , result , index + 1);
        result.push_back(v[index]);
        subset( v , result , index + 1);

        result.pop_back();
    }


  // Iterative Approach using Bitmask
void subset(vector<ll> &v)
{
    ll n = v.size();
    for (ll i = 1; i < (1LL << n); i++)
    {
        for (ll j = 0; j < n; j++)
        {
            if( i & (1LL << j) ) cout << v[j] << " ";
        }
        cout << endl;
    }
}
