#include<bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define all(a) a.begin(),a.end()
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;

int main() {
    fast_io;
    long long int n; cin >> n; cout << n << " ";
    while (n != 1) {
        if (n % 2 == 0) {
            n /= 2; cout << n << " ";
        } else {
            n = (n * 3) + 1; cout << n << " ";
        }
    }
}
