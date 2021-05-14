#include<bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define mod 1000000007
#define lli long long int
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
lli power(lli b, lli n, lli m) {
    lli res = 1;
    while (n) {
        if (n % 2) {
            res = ((res % m) * ( b % m)) % m; n--;
        }
        else {
            b = (b % m * b % m) % m; n /= 2;
        }
    }
    return res;
}
int main() {
    fast_io;
    int n; cin >> n;
    cout << power(2, n, mod);
}
