#include<bits/stdc++.h>
#define int long long
#define mod 1000000007
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define f(a,b) for(int i=a; i<b; i++)
#define rep(i,a,b) for(int i=a;i<= b;i++)
#define endl "\n"
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define fr first
#define sc second
#define INF 1000000000000000000
#define pb push_back
#define ppb pop_back()
#define sz(x) (int)((x).size())
#define vi vector<int>
using namespace std;
const int N = 2e5 + 5;
int ar[1001][1001];
int dp[1001][1001];
void test_case()
{
    int n, q; cin >> n >> q; char ch;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> ch;
            if (ch == '*') {
                ar[i][j] = 1;
            }
            else ar[i][j] = 0;
        }
    }
    int y1, x1, y2, x2;
    dp[0][0] = dp[1][0] = dp[0][1] = 0;
    if (ar[1][1] == 1) dp[1][1] = 1;
    else dp[1][1] = 0;
    rep(i, 1, n) {
        rep(j, 1, n) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + ar[i][j];
        }
    }
    // rep(i, 0, n) {
    //  rep(j, 0, n)
    //  cout << dp[i][j] << " ";
    //  cout << endl;
    // }
    while (q--) {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << (dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1]) << endl;
    }
}
signed main()
{
    fast_io;
#ifdef NCR
    init();
#endif
    int t = 1;
    // cin>>t;
    rep(i, 1, t) {
        //cout<< "Case #" << i+1 << ": " ;
        test_case();
    }
    return 0;
}
//taskkill -im main.exe -f
