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

inline void fast() { cin.tie(0)->sync_with_stdio(0); }

#if _LOCAL
#define assert(x) if (!(x)) __debugbreak()
#endif


signed main()
{
    fast();

    int k, n;
    cin >> k >> n;


    priority_queue<int> pq;
    rep(i, k)
    {
        int x;
        cin >> x;
        pq.emplace(x);
    }

    int ans = 0;
    while (n>0)
    {
        ans++;
        int t = pq.top();
        pq.pop();
        if (t >= 10)
        {
            n -= 10;
            pq.emplace(t - 10);
        }
        else n -= t;
    }
    cout << ans;

    return 0;
}
