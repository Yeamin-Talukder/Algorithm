// Time Complexity:
    // sorting query: O(Q * log Q)
    // Total :  O((N + Q) * sqrt(N))


ll block; // Block size for mo's algorithm
struct query // structure to hold each query
{
    ll l,r,index;
};

bool compare(const query &a, const query &b) // custom compare funtion for sorting
    {
        if(a.l/block == b.l/block)
        {
            return a.r < b.r;
        }
        return a.l/block < b.l/block;
    }

void mo_sort(vector<query> &q , vector<ll> &v)
{
    block = sqrt(v.size()) + 1;
    sort(q.begin() , q.end(), compare);
}

