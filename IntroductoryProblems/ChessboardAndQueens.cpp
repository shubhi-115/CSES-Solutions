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
    vector<string> s(8);
    rep(i, 0, 7) cin >> s[i];
    int p[8] = {0, 1, 2, 3, 4, 5, 6, 7};
    int ans = 0;
    do {
        bool ok = 1;
        vector<bool> d1(8, 0), d2(8, 0);
        rep(r, 0, 7) {
            if (s[r][p[r]] != '*' && d1[r + p[r]] == 0 && d2[7 - r + p[r]] == 0)
                //it should b ok in all rows
                ok &= 1, d1[r + p[r]] = 1, d2[7 - r + p[r]] = 1;
            else ok = 0;
        } ans += ok;
    } while (next_permutation(p, p + 8));
    cout << ans;
}
