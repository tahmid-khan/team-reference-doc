/**
 * Author: USACO
 * Source: https://usaco.guide/gold/all-roots?lang=cpp#solution---tree-distances-i
 * Description: It is a common technique to calculate two DP arrays for some DP on trees problems.
 *  Usually one DP array is responsible for calculating results within the subtree rooted at $i$.
 *  The other DP array calculates results outside of the subtree rooted at $i$.
 *
 *  The focus problem asks us to find for each node the maximum distance to another node.
 *  We can divide the problem into two parts. Define $f[x]$ as the maximum distance from node $x$
 *  to any node in the subtree rooted at $x$, and $g[x]$ as the maximum distance from node $x$ to
 *  any node outside of the subtree rooted at $x$. Then the answer for node $x$ is $\max(f[x],g[x])$.
 *  $f[x]$ can be calculated using a DFS since $f[x]=\max(f[c])+1$, where $c$ is a child of $x$.
 *  $g[x]$ can also be calculated using a DFS as $g[c]=\max(g[x]+1, f[d]+2)$, where $c$ and $d$ are
 *  both children of $x$ with $c \neq d$.
 *
 *  To calculate $g$ in linear time, we can define another array $h$ such that $h[x]$ is the largest
 *  distance from node $x$ to any node in the subtree rooted at $x$ excluding the child subtree that
 *  contributed to $f[x]$. So if $f[x]$ is transitioned from the branch with $c$,
 *  $g[c]=\max(g[x]+1,h[x]+1)$. Otherwise $g[c]=\max(g[x]+1,f[x]+1)$.
 * Time: O(N)
 */

vector<int> graph[200001];
int fir[200001], sec[200001], ans[200001];

void dfs1(int node = 1, int parent = 0) {
	for (int i : graph[node])
		if (i != parent) {
			dfs1(i, node);
			if (fir[i] + 1 > fir[node]) {
				sec[node] = fir[node];
				fir[node] = fir[i] + 1;
			} else if (fir[i] + 1 > sec[node]) {
				sec[node] = fir[i] + 1;
			}
		}
}

void dfs2(int node = 1, int parent = 0, int to_p = 0) {
	ans[node] = max(to_p, fir[node]);
	for (int i : graph[node])
		if (i != parent) {
			if (fir[i] + 1 == fir[node])
				dfs2(i, node, max(to_p, sec[node]) + 1);
			else dfs2(i, node, ans[node] + 1);
		}
}

int main() {
	int n; cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	dfs1();
	dfs2();
	for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
}
