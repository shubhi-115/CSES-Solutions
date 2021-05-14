#include<bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define all(a) a.begin(),a.end()
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;

int main() {
    fast_io;
    string s; cin >> s;
    int ans = 0, cnt = 1;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == s[i + 1]) cnt++;
        else cnt = 1;
        ans = max(ans, cnt);
    }
    cout << ans;
}
