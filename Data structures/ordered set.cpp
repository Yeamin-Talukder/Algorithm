
// Time Complexcity  : O(n log n) for every oparetion



#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<
    T,
    null_type,       // use mapped_type here if map-like behavior needed
    less<T>,        // comparator (greater<T> for descending order)
    rb_tree_tag,   // underlying tree structure
    tree_order_statistics_node_update
>;

// ordered_set<ll> o_set;      Declaration
// s.insert(x); 	           Insert
// s.erase(x);  	           Remove
// s.order_of_key(x);	       count element smaller than x
// *s.find_by_order(k);	       Get k-th element(index)