#include<bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define all(a) a.begin(),a.end()
using namespace std;

int main() {
    int n, x; cin >> n >> x;
    vector<int> a(n);
    for (int &i : a) cin >> i;
    sort(all(a), greater<int> ());
    if (n == 1) {cout << 1; return 0;}
    int i = 0, j = n - 1, ans = 0;
    while (i <= j) {
        if (a[i] + a[j] <= x) {
            ans++; i++; j--;
        }
        if (a[i] + a[j] > x) {
            ans++; i++;
        }
    }
    cout << ans;

}
