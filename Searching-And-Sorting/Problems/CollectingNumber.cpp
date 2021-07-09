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
    vector<int> a(n);
    map<int, int> loc; //key is value and value is its index
    rep(i, 0, n - 1) {
        cin >> a[i];
        loc[a[i]] = i;
    } ll ans = 1; int pos = loc[1];
    for (int i = 2; i <= n; i++) {
        if (loc[i] < pos)
        {   ans++;
            pos = loc[i];
        } else
            pos = loc[i];
    }
    cout << ans;
}
