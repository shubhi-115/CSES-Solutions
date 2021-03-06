#include<bits/stdc++.h>
#define int long long
#define mod 1000000007
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define f(a,b) for(int i=a; i<b; i++)
#define rep(i,a,b) for(int i=a;i<= b;i++)
#define endl "\n"
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define fr first
#define sc second
#define INF 1000000000000000000
#define pb push_back
#define ppb pop_back()
#define sz(x) (int)((x).size())
#define vi vector<int>
using namespace std;
const int N = 2e5 + 5;
const int32_t maxn = N;
template<typename NODE, typename UPDATE>
struct segtree {
    bool built = false, lazy[4 * maxn];
    NODE zero = NODE(), t[4 * maxn];
    UPDATE noop = UPDATE(), upds[4 * maxn];
    int32_t tl[4 * maxn], tr[4 * maxn];
    inline void pushdown(int32_t v)
    {
        if (lazy[v]) {
            apply(v * 2, upds[v]);
            apply(v * 2 + 1, upds[v]);
            lazy[v] = 0;
            upds[v] = noop;
        }
    }
    inline void apply(int32_t v, UPDATE &val)
    {
        if (tl[v] != tr[v]) {
            lazy[v] = 1;
            upds[v].combine(val, tl[v], tr[v]);
        }
        val.apply(t[v], tl[v], tr[v]);
    }
    template<typename T>
    void build(T &a, int32_t v, int32_t l, int32_t r) {
        tl[v] = l;
        tr[v] = r;
        if (l == r) {
            t[v] = a[l];
            return;
        } else {
            int32_t tm = (l + r) / 2;
            build(a, v * 2, l, tm);
            build(a, v * 2 + 1, tm + 1, r);
            t[v].merge(t[v * 2], t[v * 2 + 1]);
        }
    }
    NODE query(int32_t v, int l, int r) {
        if (l > tr[v] || r < tl[v])
            return zero;
        if (l <= tl[v] && tr[v] <= r) {
            return t[v];
        }
        pushdown(v);
        NODE a, b, ans;
        a = query(v * 2, l, r);
        b = query(v * 2 + 1, l, r);
        ans.merge(a, b);
        return ans;
    }
    void rupd(int32_t v, int l, int r, UPDATE &val)
    {
        if (l > tr[v] || r < tl[v])
            return;
        if (l <= tl[v] && tr[v] <= r)
        {
            apply(v, val);
            return;
        }
        pushdown(v);
        rupd(v * 2, l, r, val);
        rupd(v * 2 + 1, l, r, val);
        t[v].merge(t[v * 2], t[v * 2 + 1]);
    }
    template<typename T>
    int descent_right(int l, T x, int32_t v, NODE &prev) {
        if (l > tr[v]) // node is completely out of range
            return len;
        if (l <= tl[v]) { // node is completely in range
            NODE cur;
            cur.merge(prev, t[v]);
            if (!cur.check(x)) { // go further right than this node
                swap(prev, cur); // merging this node's contribution
                return len;
            }
            if (tl[v] == tr[v]) {
                return tr[v];
            }
        }
        pushdown(v);
        int ans = descent_right(l, x, v * 2, prev); // trying to find in left child
        if (ans != len)return ans; // found in left child
        return descent_right(l, x, v * 2 + 1, prev); // finding in right child
    }
    template<typename T>
    int descent_left(int r, T x, int32_t v, NODE &prev) {
        if (r < tl[v]) // node is completely out of range
            return -1;
        if (r >= tr[v]) { // node is completely in range
            NODE cur;
            cur.merge(t[v], prev);
            if (!cur.check(x)) { // go further left than this node
                swap(cur, prev); // merging this node's contribution
                return -1;
            }
            if (tl[v] == tr[v]) {
                return tl[v];
            }
        }
        pushdown(v);
        int ans = descent_left(r, x, v * 2 + 1, prev); // trying to find in right child
        if (ans != -1)return ans; // found in right child
        return descent_left(r, x, v * 2, prev); // finding in left child
    }

    int len = maxn;
    void clear() {
        fill(t, t + 4 * len, zero);
        fill(lazy, lazy + 4 * len, false);
        fill(upds, upds + 4 * len, noop);
        built = false;
    }
    template<typename T>
    void build(T &a) {
        build(a, 1, 0, len - 1);
        built = true;
    }
    template<typename T>
    int descent_right(int l, T x) { // minimum r such that [l...r].check(x) == true, returns segtree.len if not found
        NODE prev = zero;
        return descent_right(l, x, 1, prev);
    }
    template<typename T>
    int descent_left(int r, T x) { // maximum l such that [l...r].check(x) == true, returns -1 if not found
        NODE prev = zero;
        return descent_left(r, x, 1, prev);
    }
    NODE query(int l, int r) {
        if (!built)build(t);
        return query(1, l, r);
    }
    void rupd(int l, int r, UPDATE val) {
        if (!built)build(t);
        rupd(1, l, r, val);
    }
};

#define node node1
#define update update1
struct node {
    int value = 0;
    node() {}
    node(int val) {
        value = val;
    }
    void merge(node &l, node &r)
    {
        value = l.value + r.value;
    }
    bool check(int x) {
        return false;
    }
};
struct update {

    update() {}
    update(int val) {

    }
    void combine(update &other, int32_t tl, int32_t tr) {

    }
    void apply(node &x, int32_t tl, int32_t tr) {

    }
};
segtree<node, update> t;
#undef node
#undef update
int ar[N];
void test_case()
{
    int n, m; cin >> n >> m;
    int a, b;
    rep(i, 0, n - 1)
    cin >> ar[i];
    t.build(ar);
    while (m--) {
        cin >> a >> b;
        //because a , b is one-bases indexed in question
        cout << t.query(a - 1, b - 1).value << endl;
    }
}
signed main()
{
    fast_io;
#ifdef NCR
    init();
#endif
    int t = 1;
    // cin>>t;
    rep(i, 1, t) {
        //cout<< "Case #" << i+1 << ": " ;
        test_case();
    }
    return 0;
}
//taskkill -im main.exe -f
