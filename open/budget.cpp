#pragma GCC optimize("Ofast,inline,unroll-loops")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")

#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;

#define enablell 1

typedef long long ll;
typedef unsigned long long ull;
#if enablell
#define int ll
#define inf int(1e18)
#else
const int inf = int(2e9);
#endif
typedef vector<ull> vull;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<vvb> vvvb;
typedef pair<int, int> p2;
typedef vector<p2> vp2;
typedef vector<vp2> vvp2;
typedef vector<vvp2> vvvp2;
typedef tuple<int, int, int> p3;
typedef vector<p3> vp3;
typedef vector<vp3> vvp3;
typedef vector<vvp3> vvvp3;
typedef tuple<int, int, int, int> p4;
typedef vector<p4> vp4;

#define rep(i, high) for (int i = 0; i < high; i++)
#define repp(i, low, high) for (int i = low; i < high; i++)
#define repe(i, container) for (auto& i : container)
#define per(i, high) for (int i = high-1; i >= 0; i--)

#define _LOCAL _MSC_VER > 0
#if _LOCAL

#define assert(x) debassert(x)
#define popcount(x) __popcnt(x)
uint32_t ctz(uint32_t x) { return _tzcnt_u32(x); }
#else
#define popcount(x) __builtin_popcountll(x)
uint32_t ctz(uint32_t x) { return __builtin_ctzll(x); }

#if 0
namespace pbds
{
	using namespace __gnu_pbds;

	template<typename T> using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
	template<typename T, typename U> using indexed_map = tree<T, U, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

	struct chash { // large odd number for C
		const uint64_t C = ll(4e18 * acos(0)) | 71;
		ll operator()(ll x) const { return __builtin_bswap64(x * C); }
	};
	template<typename T, typename U> using fast_map = __gnu_pbds::gp_hash_table<T, U, chash>;
	template<typename T> using fast_set = __gnu_pbds::gp_hash_table<T, null_type, chash>;
	template<typename T, typename H> using fast_set_h = __gnu_pbds::gp_hash_table<T, null_type, H>;
}
using namespace pbds;
#endif
#endif

inline void fast() { ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }
#define FAST_INPUT 0
#if FAST_INPUT && !_LOCAL
#define gc() getchar_unlocked()
inline void read(int& v) { v = 0; int sign = 1; char c = gc(); if (c == '-') { sign = -1; } else { v += c - '0'; } while ((c = gc()) && c != ' ' && c != '\n') { if (c == EOF) { v = -1; return; } v *= 10; v += c - '0'; } v *= sign; }
inline void read(int& u, int& v) { read(u); read(v); }
inline void read(int& u, int& v, int& k) { read(u); read(v); read(k); }
//inline void read(int& v) { char c; while ((c = getchar()) != EOF && c != ' ' && c != '\n') { v *= 10; v += c - '0'; } }
inline void read(string& s) { char c; while ((c = gc()) != EOF && c != '\n' && c != ' ') { s.push_back(c); } }
inline void readline(string& s) { char c; while ((c = gc()) != EOF && c != '\n') { s.push_back(c); } }
#else
template <typename T> inline void read(T& a) { cin >> a; }
inline void read(p2& a) { cin >> a.first >> a.second; }
#endif

#define quit cout << flush; _Exit(0);
void readinput() {} // Recursion base case
template<typename T, typename... Args> void readinput(T& arg, Args&... args) { read(arg); readinput(args...); }
#define dread(type, ...) type __VA_ARGS__; readinput(__VA_ARGS__);
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (T& u : v) read(u); return is; }
#define _ << " " <<

#ifdef _DEBUG
#define noop cout << "";
#define deb __debugbreak();
#define debassert(expr) if(!(expr)) deb;
#define debif(expr) if(expr) deb;
#else
#define noop ;
#define deb ;
#define debif(expr) ;
#define debassert(expr) ;
#endif

#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define setcontains(set, x) (set.find(x) != set.end())
#define sz(container) ((int)container.size())
#define mp(a,b) (make_pair(a,b))

#define ceildiv(x,y) ((x + y - 1) / y)
ll binpow(ll a, ll b) { ll res = 1; while (b > 0) { if (b & 1) res = res * a; a = a * a; b >>= 1; } return res; }
ll binpow(ll a, ll b, ll m) { a %= m; long long res = 1; while (b > 0) { if (b & 1) res = res * a % m; a = a * a % m; b >>= 1; } return res; } // For a < 2^31

template <typename T, typename U> inline void operator+=(pair<T, U>& l, const pair<T, U>& r) { l = { l.first + r.first,l.second + r.second }; }
template <typename T, typename U> inline pair<T, U> operator+(const pair<T, U> l, const pair<T, U> r) { return { l.first + r.first, l.second + r.second }; }
template <typename T, typename U> inline pair<T, U> operator-(const pair<T, U> l, const pair<T, U> r) { return { l.first - r.first, l.second - r.second }; }
template <typename T, typename U> inline pair<T, U> operator*(const pair<T, U> l, const int m) { return { l.first * m, l.second * m }; }
vector<string> split(string s, string d) { size_t k = 0, n, e = d.length(); string t; vector<string> r; while ((n = s.find(d, k)) != string::npos) { t = s.substr(k, n - k); k = n + e; r.push_back(t); } r.push_back(s.substr(k)); return r; }

#if 1
auto Start = chrono::high_resolution_clock::now();
void resettimer() { Start = chrono::high_resolution_clock::now(); }
int elapsedmillis() { return chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - Start).count(); }
random_device rd;
mt19937 rng(rd());
template<typename T, typename U> inline int randint(T lo, U hi) { return uniform_int_distribution<int>((int)lo, (int)hi)(rng); } // [lo,hi]
template<typename T> inline T randel(vector<T>& v) { return v[uniform_int_distribution<int>(int(0), int(v.size()) - int(1))(rng)]; } // [lo,hi]
#endif
const ll mod = 1e9 + 7;
vp2 dirs = { {0,1},{0,-1},{1,0},{-1,0} };


struct PushRelabel {
	struct Edge {
		int dest, back;
		ll f, c;
	};
	vector<vector<Edge>> g;
	vector<ll> ec;
	vector<Edge*> cur;
	vector<vi> hs; vi H;
	PushRelabel(int n) : g(n), ec(n), cur(n), hs(2 * n), H(n) {}

	void addEdge(int s, int t, ll cap, ll rcap = 0) {
		//cout << s << " " << t << " " << cap << "\n";
		if (s == t) return;
		g[s].push_back({ t, sz(g[t]), 0, cap });
		g[t].push_back({ s, sz(g[s]) - 1, 0, rcap });
	}

	void addFlow(Edge& e, ll f) {
		Edge& back = g[e.dest][e.back];
		if (!ec[e.dest] && f) hs[H[e.dest]].push_back(e.dest);
		e.f += f; e.c -= f; ec[e.dest] += f;
		back.f -= f; back.c += f; ec[back.dest] -= f;
	}
	ll calc(int s, int t) {
		int v = sz(g); H[s] = v; ec[t] = 1;
		vi co(2 * v); co[0] = v - 1;
		repp(i, 0, v) cur[i] = g[i].data();
		for (Edge& e : g[s]) addFlow(e, e.c);

		for (int hi = 0;;) {
			while (hs[hi].empty()) if (!hi--) return -ec[s];
			int u = hs[hi].back(); hs[hi].pop_back();
			while (ec[u] > 0)  // discharge u
				if (cur[u] == g[u].data() + sz(g[u])) {
					H[u] = 1e9;
					for (Edge& e : g[u]) if (e.c && H[u] > H[e.dest] + 1)
						H[u] = H[e.dest] + 1, cur[u] = &e;
					if (++co[H[u]], !--co[hi] && hi < v)
						repp(i, 0, v) if (hi < H[i] && H[i] < v)
						--co[H[i]], H[i] = v + 1;
					hi = H[u];
				}
				else if (cur[u]->c && H[u] == H[cur[u]->dest] + 1)
					addFlow(*cur[u], min(ec[u], cur[u]->c));
				else ++cur[u];
		}
	}
	bool leftOfMinCut(int a) { return H[a] >= sz(g); }
};

struct edge
{
	int from, to, lo, hi;
};
typedef PushRelabel flowAlgorithm;
// Returns null if no feasible flow exists with given lower bounds
// To find min flow satisfying constraints, binary search for smallest capacity giving feasible solution
flowAlgorithm* lowerbound_flow(vector<edge>& edges, int n, int source, int sink, int capacity = inf)
{
	flowAlgorithm* flow = new flowAlgorithm(n + 2);
	vi outflow(n), inflow(n);
	repe(e, edges)
	{
		outflow[e.from] += e.lo;
		inflow[e.to] += e.lo;
		flow->addEdge(e.from, e.to, e.hi - e.lo);
	}
	rep(i, n)
	{
		flow->addEdge(n, i, inflow[i]);
		flow->addEdge(i, n + 1, outflow[i]);
	}
	flow->addEdge(sink, source, capacity);

	return flow->calc(n, n + 1) == accumulate(all(outflow), 0) ? flow : nullptr;
}

int32_t main()
{
	fast();
#if 0 && _LOCAL
	ifstream instream("C:\\users\\matis\\source\\repos\\comp_prog\\x64\\debug\\in.txt");
	cin.rdbuf(instream.rdbuf());
#endif

	dread(int, t);
	while (t--)
	{
		dread(int, n, m);
		vi rowsums(n);
		vi colsums(m);
		cin >> rowsums >> colsums;

		dread(int, k);
		vector<edge> edges;
		vvi low(n, vi(m, 0));
		vvi hi(n, vi(m, inf));
		rep(i, k)
		{
			dread(int, a, b);
			a--; b--;
			p2 upd = { -inf,inf };
			dread(char, c);
			dread(int, v);
			if (c == '>') upd.first = v + 1;
			if (c == '<') upd.second = v - 1;
			if (c == '=') upd = p2(v, v);

			if (a == -1 && b == -1)
			{
				rep(i, n)rep(j, m) low[i][j] = max(low[i][j], upd.first);
				rep(i, n)rep(j, m) hi[i][j] = min(hi[i][j], upd.second);
			}
			else if (a == -1)
			{
				rep(i, n) low[i][b] = max(low[i][b], upd.first);
				rep(i, n) hi[i][b] = min(hi[i][b], upd.second);
			}
			else if (b == -1)
			{
				rep(j, m) low[a][j] = max(low[a][j], upd.first);
				rep(j, m) hi[a][j] = min(hi[a][j], upd.second);
			}
			else
			{
				low[a][b] = max(low[a][b], upd.first);
				hi[a][b] = min(hi[a][b], upd.second);
			}
		}

		rep(i, n)
		{
			edges.emplace_back(edge{ n + m,i,rowsums[i],rowsums[i] });
		}
		rep(i, m)
		{
			edges.emplace_back(edge{ n + i,n + m + 1, colsums[i],colsums[i] });
		}
		int lowsum = accumulate(all(rowsums), 0) + accumulate(all(colsums), 0);
		rep(i, n)
		{
			rep(j, m)
			{
				edges.emplace_back(edge{ i,n + j, low[i][j],hi[i][j] });
				lowsum += low[i][j];
			}
		}


		PushRelabel* flowptr = lowerbound_flow(edges, n + m + 2, n + m, n + m + 1);

		if (flowptr != nullptr)
		{
			PushRelabel flow = *flowptr;
			//cout << "FEASIBLE";
			vvi ans(n, vi(m));
			rep(i, flow.g.size())
			{
				repe(e, flow.g[i])
				{
					if (i < n && (e.dest >= n && e.dest < n + m))
					{
						ans[i][e.dest - n] += e.f;
					}
				}
			}
			rep(i, n)
			{
				rep(j, m)
				{
					cout << (low[i][j] + ans[i][j]) << " ";
				}
				if (!(i == n - 1 && t == 0)) cout << "\n";
			}
		}
		else
		{
			cout << "IMPOSSIBLE";
			if (t) cout << "\n";
		}
	}

	quit;
}