
class segment_tree
{

public : 

vector<ll>save,lazy;

segment_tree(ll size)
{
    save.resize(4*size);
    lazy.resize(4*size);
}

void create(ll node,ll start,ll end,vector<ll>&v)
{
if(start== end) {   save[node]=/*save_your_data_here*/;    return;}

ll mid = (start+end)/2;
create(node*2,start,mid,v);
create((node*2)+1,mid+1,end,v);

save[node]=/*save_your_data_here_when_geting_up*/; 
}

void update(ll node,ll start , ll end,ll l ,ll r,ll value)
{
if(start>r || end<l)return;

if(l<=start && end <=r)
{
    lazy[node]+=/*save_your_data_here*/;
    save[node]+=/*save_your_data_here*/;
    return;
}

ll mid = (start+end)/2;
update(node*2,start,mid,l,r,value);
update((node*2)+1,mid+1,end,l,r,value); 

save[node]=/*save_your_data_here_when_geting_up*/; 

}

void query(ll node,ll start , ll end,ll l,ll r,ll carry,ll &ans)
{

if(start>r || end<l)return;
if(l<=start && end<=r ){ans+=/*save_your_data_here*/;  return;}
ll mid=(start+end)/2;

query(node*2,start,mid,l,r,carry+lazy[node],ans);
query((node*2)+1,mid+1,end,l,r,carry+lazy[node],ans);

}


};



// create an object  of segment_tree like
// -> "segment_tree* segment = new segment_tree(n);" 
// -> "segment_tree segment(n);"  
//---- first one for pointer type and second one is normal way and n use for vector size declared

// -- declare create methode of the segment_tree first before use
// use node value 1 everywhere
// use 0 based index 
// use a ans variable for geting query ans in it

