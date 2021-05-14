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
#define INF 1000000000
#define pb push_back
#define ppb pop_back()
#define sz(x) (int)((x).size())
using namespace std;

int main() {
    int t; cin >> t; while (t--) {
        ll a, b; cin >> a >> b;
        if ((a + b) % 3) cout << "NO";
        else {
            if (a > b) swap(a, b);
            ll mx = (b / 2) + (b % 2);
            if (a >= mx) cout << "YES";
            else cout << "NO";
        }
        cout << endl;
    }
    return 0;
}
