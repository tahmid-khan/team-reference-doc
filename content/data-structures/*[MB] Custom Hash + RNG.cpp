/**
 * Author: Mohammed Bashem
 * Description: custom hash and hash map
 */

#include <bits/extc++.h>
using namespace __gnu_pbds;
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
unordered_map<int, int, custom_hash> mp;
gp_hash_table<int, int, custom_hash> mp;

// random number generator
// shuffle => shuffle(all(a), rng);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int ran(int l, int r)
{
    return uniform_int_distribution<int>(l, r)(rng);
}
