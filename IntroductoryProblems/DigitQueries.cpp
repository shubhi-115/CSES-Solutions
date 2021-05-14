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
#define int ll
using namespace std;
void solve(int t) {
    int dig = 1;
    while (1) {
        int mn = 1, mx = 9;
        for (int i = 1; i < dig; i++) { //if 4 digit no so loop will run 3 times
            mn *= 10;
            mx *= 10; mx += 9;
        }
        int cnt = mx - (mn - 1);
        if (t <= dig * cnt) //dig*cnt gives the current index
            break;
        t -= (dig * cnt);
        dig++;
    }
    int mn = 1;
    rep(i, 1, dig - 1) mn *= 10;
    int x = (t / dig) - (t % dig == 0);//to prevent 0 index
    mn += x;
    t -= dig * x;
    string s = to_string(mn);
    cout << s[t - 1] << endl;
}
signed main() {
    fast_io;
    int q; cin >> q; while (q--) {
        int t; cin >> t;
        solve(t);
    }
}
