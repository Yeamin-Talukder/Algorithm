

// Time Complexity: O(n^2)


class pascal_triangle
{
    public:

    vector<vector<ll>> nCr;       // This nCr vector will have the data
    pascal_triangle(ll size )
    {
         nCr.resize(size+1);

        for (ll i = 0; i < size+1; i++) 
        {

            for (ll j = 0; j <= (i+1)/2 ; j++) 
            {

            if(j == 0)  nCr[i].push_back(1);
            else if(j == i) nCr[i].push_back(1);
            else nCr[i].push_back( (nCr[i][j-1] * (i-j+1)) / j);
        
            }

        }

    }
    // To use this just create a object of this and use the vector nCr
    // Also remember you need to reduce the r value if r > (n/2) 
};