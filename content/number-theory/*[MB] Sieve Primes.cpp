/**
 * Author: Mohammed Bashem
 * Description: sieve primes
 */
vector<ll> segemented_sieve(ll l, ll r) {
    vector<ll> seg_primes;
    vector<bool> current_primes(r - l + 1, true);
    for (ll p : primes) {
        ll to = (l / p) * p;
        if (to < l) to += p;
        if (to == p) to += p;
        for (ll i = to; i <= r; i += p)
            current_primes[i - l] = false;
    }
    for (ll i = l; i <= r; i++) {
        if (i < 2) continue;
        if (current_primes[i - l]) seg_primes.push_back(i);
    }
    return seg_primes;
}
