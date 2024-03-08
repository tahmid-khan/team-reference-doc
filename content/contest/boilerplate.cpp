#include <bits/stdc++.h>
using namespace std;

template<typename A, typename B> ostream& operator<<(ostream& os, const pair<A, B>& p) {
	return os << '(' << p.first << ", " << p.second << ')';
}
template<typename C, typename T = typename enable_if<!is_same<C, string>::value, typename C::value_type>::type> ostream& operator<<(ostream& os, const C& v) {
	os << '{';
	string sep;
	for (const T& x : v)
		os << sep << x, sep = ", ";
	return os << '}';
}

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
	#define dbg(...) cerr << '[' << __FILE__ << ':' << __LINE__ << "] (" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
	#define dbg(...)
#endif

#define all(x) begin(x), end(x)
#define len(x) (int(size(x)))
#define mem(x, n) memset(x, n, sizeof(x))

void solve() {}

int main() {
	ios_base::sync_with_stdio(false);
#ifndef LOCAL
	cin.tie(nullptr);
#endif

	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cout << "Case " << i << ": ";
		solve();
	}
}
