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
#define INF 1000000000
#define pb push_back
#define ppb pop_back()
#define sz(x) (int)((x).size())
using namespace std;
//gfg=>https://www.geeksforgeeks.org/generate-n-bit-gray-codes/
int main() {
    fast_io;
    int n; cin >> n;
    vector<string> prev = {"0", "1"};
    while (prev.size() != (1 << n)) {
        vector<string> l1 = prev;
        vector<string> l2 = l1;
        reverse(all(l2));
        prev.clear();
        for (auto ele : l1)
            ele = '0' + ele, prev.pb(ele);
        for (auto ele : l2)
            ele = '1' + ele, prev.pb(ele);

    }
    for (string s : prev) {
        cout << s << endl;
    }
}
