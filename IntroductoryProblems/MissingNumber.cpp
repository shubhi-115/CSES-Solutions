#include<bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define all(a) a.begin(),a.end()
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define mod 1000000007
using namespace std;

int main() {
    fast_io;
    long long n; cin >> n;
    long long sum = 0;
    rep(i, 0, n - 2) {
        long long int x; cin >> x;
        sum += x;
    }
    long long int tot = n * (n + 1) / 2;
    cout << (tot - sum);
}
