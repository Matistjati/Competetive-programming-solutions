#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int ll
const int inf = int(1e18);

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> p2;

#define rep(i, high) for (int i = 0; i < (high); i++)
#define repp(i, low, high) for (int i = (low); i < (high); i++)
#define repe(i, container) for (auto& i : container)
#define sz(container) ((int)container.size())
#define all(x) begin(x),end(x)

inline void fast() { ios::sync_with_stdio(0); cin.tie(0); }

#if _LOCAL
#define assert(x) if (!(x)) __debugbreak()
#endif



signed main()
{
    fast();

    int n;
    cin >> n;
    map<set<int>, int> dist;
    int ans = 0;
    rep(i, n)
    {
        set<int> student;
        rep(j, 5)
        {
            int v;
            cin >> v;
            student.insert(v);
        }
        dist[student]++;
        ans = max(ans, dist[student]);
    }
    int cnt = 0;
    repe(u, dist) cnt += (u.second == ans) * u.second;
    cout << cnt;

    return 0;
}
