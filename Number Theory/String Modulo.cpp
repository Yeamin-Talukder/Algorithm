
// This method is similar to our childhood method of finding the remainder of a number when divided by another number. 

bool string_modulo(string a , ll b)
{
    ll val = 0;
    for(auto c:a)
    {
        if( c == '-') continue;
        val = (val * 10 + (c - '0')) % b;
    }

    if(val == 0) return true; 
    else return false;
    
}
