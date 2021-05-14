#include<bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define all(a) a.begin(),a.end()
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;

int main() {
    int n; cin >> n;
    vector<pair<int, int>> v(n), end(n);

    rep(i, 0, n - 1) {
        int x, y; cin >> x >> y;
        v[i] = {x, y};
        end[i] = {y, i};
    }
    sort(all(end));
    int ans = 0, last = -1;
    rep(i, 0, n - 1) {
        if (v[end[i].second].first >= last) {
            ans++;
            last = end[i].first;
        }
    }
    cout << ans;
}

