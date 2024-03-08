/**
 * Author: Nadman Khan
 * Description: order statistic tree
 */

#include <bits/extc++.h>
namespace pbds = __gnu_pbds;

// - `find_by_order(i)` to get the `i`-th element (0-indexed)
// - `order_of_key(k)` to get the number of elements/keys strictly smaller than the key `k`
template <class Key,
          class Cmp_Fn = std::less<Key>>
using Ordered_Set = pbds::tree<Key,
                               pbds::null_type,
                               Cmp_Fn,
                               pbds::rb_tree_tag,
                               pbds::tree_order_statistics_node_update>;

template <class Key,
          class Mapped,
          class Hash_Fn = std::hash<Key>,
          class Eq_Fn = std::equal_to<Key>>
using Hash_Map = pbds::gp_hash_table<Key,
                                     Mapped,
                                     Hash_Fn,
                                     Eq_Fn>;
