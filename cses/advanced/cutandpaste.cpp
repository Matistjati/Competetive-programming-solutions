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

struct node
{
    int key, prio, cnt;
    node* l, * r;
    node() {}
    node(int key) : key(key), prio(randint(1, int(1e9))), cnt(1), l(nullptr), r(nullptr) {}
};
typedef node* pnode;

int cnt(pnode t) {
    return t ? t->cnt : 0;
}

void upd_cnt(pnode t) {
    if (t)
        t->cnt = 1 + cnt(t->l) + cnt(t->r);
}

void merge(pnode& x, pnode l, pnode r)
{
    if (!l || !r)
        x = l ? l : r;
    else if (l->prio > r->prio)
        merge(l->r, l->r, r), x = l;
    else
        merge(r->l, l, r->l), x = r;
    upd_cnt(x);
}

void split(pnode x, int key, pnode& l, pnode& r, int add = 0)
{
    if (!x)
        return void(l = r = nullptr);
    int real_key = add + cnt(x->l);
    if (key <= real_key)
        split(x->l, key, l, x->l, add), r = x;
    else
        split(x->r, key, x->r, r, add + 1 + cnt(x->l)), l = x;
    upd_cnt(x);
}

void insert(pnode& x, int pos, int key)
{
    pnode l = new node(inf);
    pnode r = new node(inf);
    split(x, pos, l, r);
    pnode item = new node(key);
    merge(l, l, item);
    merge(x, l, r);
}

void output(pnode t) {
    if (!t)  return;
    output(t->l);
    cout << (char)t->key << " ";
    output(t->r);
}

int kth(pnode& x, int k)
{
    if (k == cnt(x->l)) return x->key;
    if (k <= cnt(x->l))
        return kth(x->l, k);
    return kth(x->r, k - cnt(x->l) - 1);
}


int32_t main()
{
    fast();
#if 0 && _LOCAL
    ifstream instream("C:\\users\\matis\\source\\repos\\comp_prog\\x64\\debug\\in.txt");
    cin.rdbuf(instream.rdbuf());
#endif

    dread(int, n, q);
    dread(string, s);
    pnode root = new node(s[0]);
    repp(i, 1, s.size())
    {
        insert(root, i, s[i]);
    }

    while (q--)
    {
        dread(int, l, r);
        pnode lnode, midnode, rnode;
        split(root, r, midnode, rnode);
        split(midnode, l - 1, lnode, midnode);
        //output(lnode); cout << "\n";
        //output(midnode); cout << "\n";
        //output(rnode); cout << "\n";
        merge(rnode, rnode, midnode);
        merge(lnode, lnode, rnode);
    }

    rep(i, n)
    {
        cout << (char)kth(root, i);
    }

    quit;
}