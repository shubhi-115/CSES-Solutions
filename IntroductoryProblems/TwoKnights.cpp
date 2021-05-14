#include<bits/stdc++.h>;
#define int long long
#define mod 1000000007
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define f(a,b) for(int i=a; i<b; i++)
#define rep(i,a,b) for(int i=a;i< b;i++)
#define endl "\n"
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define fr first
#define sc second
#define INF 1000000000
#define pb push_back
#define ppb pop_back()
#define sz(x) (int)((x).size())
using namespace std;
const int N = 1e4 + 5;
int a[N];
pii mv[8] = {{2, 1}, {2, -1}, { -2, 1}, { -2, -1}, {1, 2}, { -1, 2}, {1, -2}, { -1, -2}};
bool valid(int r, int c, int k)
{
    return r >= 0 && r < k && c >= 0 && c < k;
}
int not_valid(int r, int c, int k)
{
    int cnt = 0;
    for (pii x : mv)
    {
        if (valid(r + x.fr, c + x.sc, k)) cnt++;
    }
    return cnt;
}
void solve()
{
    int n;
    cin >> n;
    //cout<< n<< endl;
    rep(i, 1, n + 1) cout << a[i] << endl;
}
signed main()
{
    fast_io;
    int t = 1;
    //cin>>t;
    a[1] = 0;
    a[2] = 6;
    rep(k, 3, 1e4 + 1)
    {
        int ways = 0;
        if (k > 4) ways += (k - 4) * (k - 4) * (k * k - 9);
        ways += (4) * ((k * k) - 3);
        int t = 0;
        rep(c, 1, k - 1)
        {
            t += k * k - not_valid(0, c, k) - 1;
        }
        //cout<< "dfd" << " " << t << endl;
        ways += t * 4;
        //cout<< ways << endl;
        if (k > 3) ways += 4 * (k * k - 5);
        else if (k == 3) ways += k * k - 1;

        if (k > 4) ways += 4 * (k - 4) * (k * k - 7);
        a[k] = ways / 2;
    }
    while (t--) {
        solve();
    }
    return 0;
}
