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

int main() {
    fast_io;
    int n; cin >> n;
    vector<int> ar(n);
    rep(i, 0, n - 1) cin >> ar[i];
    sort(all(ar)); ll ans = 0;
    rep(i, 0, n - 1) {
        ans += (abs(ar[i] - ar[n / 2]));
    }
    cout << ans;
}
