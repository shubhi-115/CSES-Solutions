#include<bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

int main() {
    int n; cin >> n;
    set<int> s;
    for (int i = 0; i < n; i++) {
        int x; cin >> x; s.insert(x);
    }
    cout << s.size();
}
