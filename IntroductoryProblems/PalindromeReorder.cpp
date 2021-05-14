#include<bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define mod 1000000007
#define ll long long int
#define rep(i,a,b) for(int i=a;i<=b;i++)
// #define endl "\n"
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

int main() {
    fast_io;
    string s; cin >> s;
    int n = s.length();
    map<char, int> mp;
    for (char &ch : s) mp[ch]++;
    int odd_count_present = 0;
    for (auto x : mp) {
        if (x.sc % 2 == 1) {
            if (odd_count_present == 0) odd_count_present++;
            else {cout << "NO SOLUTION"; return 0;}
        }
    }
    if ((n % 2 == 1 && odd_count_present != 1) || (n % 2 == 0 && odd_count_present != 0))
    {cout << "NO SOLUTION"; return 0;}
    vector<char> ans(n); int l = 0, h = n - 1; char odd_char = ' ';
    for (auto x : mp) {
        if (x.sc % 2 == 0) {
            int temp = x.sc / 2;
            while (temp--) {
                ans[l++] = x.fr;
                ans[h--] = x.fr;
            }
        } else {
            odd_char = x.fr;
            int temp = x.sc / 2;
            while (temp--) {
                ans[l++] = x.fr;
                ans[h--] = x.fr;
            }
        }
    }
    if (odd_count_present) ans[l] = odd_char;
    for (auto e : ans) cout << e;

}
