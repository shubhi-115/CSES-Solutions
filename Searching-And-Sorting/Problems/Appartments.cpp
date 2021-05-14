#include<bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

int main() {
//n is number of aplicant and m is no of appartments.....a is desired size and b array is actual size
    int n, m, k; cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
// i is the pointer to a(desired size array) & j is the pointer to b(appartment size array)
    int i = 0, j = 0, ans = 0;
    while (i < n && j < m) {
        if (a[i] - k <= b[j]  &&   b[j] <= a[i] + k) {
            ans++; i++; j++;
        }
        if (b[j] < a[i] - k) j++;
        if (b[j] > a[i] + k) i++;
    }
    cout << ans;
}
