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
const int N = 2e5 + 1;
vector<int> tree[N];
vector<vector<int>> dp(N, vector<int>(2));

void dfs(int v, int par = -1) {
  for (int child : tree[v]) {
    if (child != par) {
      dfs(child, v);
      dp[v][0] += max(dp[child][0], dp[child][1]);
    }
  }
  //how to calculate dp[v][1]
  for (int child : tree[v]) {
    int ans = 1 + dp[v][0];
    if (child == v) continue;
    ans -= max(dp[child][0], dp[child][1]);
    ans += dp[child][0];
    dp[v][1] = max(dp[v][1], ans);
  }

}
int main() {
  fast_io;
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int u, v; cin >> u >> v;
    tree[u].push_back(v);
    tree[v].push_back(u);
  }
  dfs(1);
  cout << max(dp[1][0], dp[1][1]);
}

