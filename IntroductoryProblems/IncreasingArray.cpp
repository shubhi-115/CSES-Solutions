#include<bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define all(a) a.begin(),a.end()
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;

int main() {
    int n; cin >> n; long long int ans = 0;
    vector<int> ar(n);
    rep(i, 0, n - 1)
    cin >> ar[i];
    rep(i, 1, n - 1) {
        if (ar[i - 1] <= ar[i]) continue;
        else {
            long long int diff = ar[i - 1] - ar[i];
            ans += diff;
            ar[i] = ar[i] + diff;
        }
    }
    cout << ans;
}
