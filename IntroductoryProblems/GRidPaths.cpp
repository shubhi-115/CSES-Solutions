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
string s; int ans;
bool vis[7][7];
bool e(int i , int j) {
    return (i >= 0 && j < 7 && i < 7 && j >= 0 && !vis[i][j]);
}

void dfs(int i, int j, int a = 0) {
    if (i == 6 && j == 0) {
        if (a == 48)
            ++ans;
        return ;
    } vis[i][j] = 1;
    if (s[a] == '?' || s[a] == 'L') {
        if (j > 0 && !vis[i][j - 1])
            if (!(!e(i, j - 2) && e(i + 1, j - 1) && e(i - 1, j - 1)))
                dfs(i, j - 1, a + 1);
    }
    if (s[a] == '?' || s[a] == 'R') {
        if (j < 6 && !vis[i][j + 1])
            if (!(!e(i, j + 2) && e(i + 1, j + 1) && e(i - 1, j + 1)))
                dfs(i, j + 1, a + 1);
    }
    if (s[a] == '?' || s[a] == 'U') {
        if (i > 0 && !vis[i - 1][j])
            if (!(!e(i - 2, j) && e(i - 1, j + 1) && e(i - 1, j - 1)))
                dfs(i - 1, j, a + 1);
    }
    if (s[a] == '?' || s[a] == 'D') {
        if (i < 6 && !vis[i + 1][j])
            if (!(!e(i + 2, j) && e(i + 1, j + 1) && e(i + 1, j - 1)))
                dfs(i + 1, j, a + 1);
    }
    vis[i][j] = 0;
}
int main() {
    fast_io;
    cin >> s;
    dfs(0, 0);
    cout << ans;
}
