#include <ext/pb_ds/assoc_container.hpp>
const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash { int operator()(int x) const { return x ^ RANDOM; } };

template<typename K, typename V, class Hash_Fn>
class hash_table : public __gnu_pbds::gp_hash_table<K,V,Hash_Fn> {
    public: bool count(K key) { return this->find(key) != this->end(); }
};

hash_table<int,int,chash> table;
