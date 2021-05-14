#include<bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define all(a) a.begin(),a.end()
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;

int main() {
    int n; cin >> n;
    vector<pair<int, int>> v(n);
    rep(i, 0, n - 1) {
        int x, y;   cin >> x >> y;
        v[i] = {x, y};
    }
    sort(all(v));
    multiset<int> end; int curr = 0; int ans = INT_MIN;
    rep(i, 0, n - 1) {
        curr++;
        while (!end.empty() && *end.begin() < v[i].first) {
            curr--; end.erase(end.begin());
        }
        ans = max(ans, curr);
        end.insert(v[i].second);
    }
    cout << ans;
}
