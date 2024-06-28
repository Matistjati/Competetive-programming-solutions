#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int ll
const int inf = int(1e18);

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> p2;

#define rep(i, high) for (int i = 0; i < high; i++)
#define repp(i, low, high) for (int i = low; i < high; i++)
#define repe(i, container) for (auto& i : container)
#define sz(container) ((int)container.size())
#define all(x) begin(x),end(x)
#define ceildiv(x,y) (((x) + (y) - 1) / (y))

inline void fast() { ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }

#if _LOCAL
#define assert(x) if (!(x)) __debugbreak()
#endif


bool dfs(int a, int L, vector<vi>& g, vi& btoa, vi& A, vi& B) {
	if (A[a] != L) return 0;
	A[a] = -1;
	for (int b : g[a]) if (B[b] == L + 1) {
		B[b] = 0;
		if (btoa[b] == -1 || dfs(btoa[b], L + 1, g, btoa, A, B))
			return btoa[b] = a, 1;
	}
	return 0;
}

int hopcroftKarp(vector<vi>& g, vi& btoa) {
	int res = 0;
	vi A(g.size()), B(btoa.size()), cur, next;
	for (;;) {
		fill(all(A), 0);
		fill(all(B), 0);
		/// Find the starting nodes for BFS (i.e. layer 0).
		cur.clear();
		for (int a : btoa) if (a != -1) A[a] = -1;
		repp(a, 0, sz(g)) if (A[a] == 0) cur.push_back(a);
		/// Find all layers using bfs.
		for (int lay = 1;; lay++) {
			bool islast = 0;
			next.clear();
			for (int a : cur) for (int b : g[a]) {
				if (btoa[b] == -1) {
					B[b] = lay;
					islast = 1;
				}
				else if (btoa[b] != a && !B[b]) {
					B[b] = lay;
					next.push_back(btoa[b]);
				}
			}
			if (islast) break;
			if (next.empty()) return res;
			for (int a : next) A[a] = lay;
			cur.swap(next);
		}
		/// Use DFS to scan for augmenting paths.
		repp(a, 0, sz(g))
			res += dfs(a, 0, g, btoa, A, B);
	}
}

int parsetime(string x)
{
	int h = stoi(x.substr(0, 2));
	rep(i, 3) x.erase(x.begin());
	return h * 60 + stoi(x);
}

signed main()
{
    fast();

    int t;
    cin >> t;
    while (t--)
    {
		int n;
		cin >> n;
		vi btoa(n, -1);
		vvi edges(n);
		vi time(n);
		vector<p2> endpos(n);
		rep(i, n)
		{
			string ride_time;
			cin >> ride_time;
			p2 start;
			p2 end;
			cin >> start.first >> start.second >> end.first >> end.second;


			endpos[i] = end;
			int ride_start = parsetime(ride_time);
			time[i] = ride_start + abs(start.first - end.first) + abs(start.second - end.second);
			rep(j, i)
			{
				int final_time = time[j] + abs(start.first - endpos[j].first) + abs(start.second - endpos[j].second);
				if (final_time<ride_start)
				{
					edges[j].push_back(i);
				}
			}
		}
		cout << n-hopcroftKarp(edges, btoa) << "\n";
    }

    return 0;
}
