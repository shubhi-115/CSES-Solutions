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

signed main() {
    fast_io;
    int n; cin >> n;
    vector<int> ar(n);
    //1 2 3 sum=>6 then another no in array should be <=7 (s+1) so that sum could be made
    //if not so that will be the mininum sum(s+1) that cant be obtained
    //ex=>1 2 3 4 5 6 7 8 9 45 =>in this array min 43 cant be made because till 9 sum is 42 so 10th element should be <=43
    rep(i, 0, n - 1) cin >> ar[i];
    sort(all(ar));
    ll s = 0;
    rep(i, 0, n - 1) {
        if (ar[i] > s + 1) {
            cout << s + 1;
            return 0;
        }
        s += ar[i];
    }
    cout << s + 1;
}
