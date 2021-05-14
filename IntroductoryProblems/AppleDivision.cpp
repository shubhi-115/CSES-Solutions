#include<bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define mod 1000000007
#define ll long long int
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define endl "\n"
#define all(a) a.begin(),a.end()
#define vi vector<int>
#define pii pair<int,int>
#define fr first
#define sc second
#define INF (ll)1e18
#define pb push_back
#define ppb pop_back()
#define sz(x) (int)((x).size())
using namespace std;
int n; int v[22]; ll ans = INF;
void rec(int pos = 0, ll s1 = 0, ll s2 = 0) {
    if (pos == n) {
        ans = min(ans, abs(s1 - s2));
        return;
    }
    rec(pos + 1, s1 + v[pos], s2);
    rec(pos + 1, s1, s2 + v[pos]);
}
int main() {
    fast_io;
    cin >> n;
    rep(i, 0, n - 1)
    cin >> v[i];
    rec();
    cout << ans << endl;
}
//Second Approach by subset by bitmasking
// int main() {
//     fast_io;
//     int n; cin >> n;
//     vector<int> ar(n);
//     rep(i, 0, n - 1) cin >> ar[i];
//     ll s1 = 0, s2 = 0; ll ans = INF;
//     for (int i = 0; i < (1 << n); i++) {
//         s1 = 0; s2 = 0;
//         for (int j = 0; j < n; j++) {
//             if (i & (1 << j))
//                 s1 += ar[j];
//             else s2 += ar[j];
//         }
//         ans = min(ans, abs(s1 - s2));
//     }
//     cout << ans;
// }
