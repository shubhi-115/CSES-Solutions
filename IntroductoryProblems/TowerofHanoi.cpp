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
//moving n-1 plates from src to helper
//moving last one plate from src to destination (base condtn)
//moving n-1 plates from helper to destination
void tower_of_hanoi(int src, int dest, int help, int n) {
    if (n == 1) {
        cout << src << ' ' << dest << endl;
        return;
    }
    tower_of_hanoi(src, help, dest, n - 1);
    cout << src << ' ' << dest << endl;
    tower_of_hanoi(help, dest, src, n - 1);
    // cout << src << ' ' << dest << endl;
}
int main() {
    fast_io;
    int n; cin >> n;
    cout << (1 << n) - 1 << endl;
    int src = 1, help = 2, dest = 3;
    tower_of_hanoi(src, dest, help, n);

}
