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
#define int long long int
using namespace std;

signed main() {
    fast_io;
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> m;
    rep(i, 0, n - 1) cin >> a[i];
    int ans = 0;
    for (int i = 0, j = 0; i < n; i++) {
        while (j < n && m[a[j]] < 1) {
            m[a[j]]++;
            j++;
        }
        ans = max(ans, j - i);
        m[a[i]]--;
    }
    cout << ans ;
}

