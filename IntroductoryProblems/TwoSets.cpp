#include<bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define endl "\n"
#define all(a) a.begin(),a.end()
#define ll long long int
#define vi vector<int>
#define pii pair<int,int>
#define fr first
#define sc second
#define INF 1000000000
#define pb push_back
#define ppb pop_back()
#define sz(x) (int)((x).size())
using namespace std;

int main() {
    int n; cin >> n;
    ll tot =  (n * 1LL * (n + 1)) / 2;
    if (tot % 2 == 1) cout << "NO" << endl;
    else {
        ll sum = tot / 2;
        vector<int> v(n + 1);
        for (int i = n; i >= 1; i--) {
            if (sum >= i) v[i] = 1, sum -= i;
            else break;
        }
        if (sum != 0) v[sum] = 1;
        cout << "YES" << endl;
        cout << accumulate(all(v), 0) << endl;
        for (int i = 1; i <= n; i++)
            if (v[i] == 1) cout << i << " ";
        cout << endl;
        cout << (n - accumulate(all(v), 0)) << endl;
        for (int i = 1; i <= n; i++)
            if (v[i] == 0) cout << i << " ";
    }
    return 0;
}
