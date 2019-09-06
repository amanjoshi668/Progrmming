#include <bits/stdc++.h>
#include <unistd.h>
//#include <ext/pb_ds/assoc_container.hpp> // Common file
//#include <ext/pb_ds/tree_policy.hpp> // Including seg_tree_order_statistics_node_update
#include <stdio.h>
#include <cassert>
using namespace std;
//using namespace __gnu_pbds;
typedef long long lo;
typedef long double ld;
#include <ctime>
typedef pair<lo, lo> ll; //pair
typedef vector<lo> vl;   //vector of long
typedef vector<ll> vll;  //vector of pair
typedef priority_queue<lo> p_q;
typedef vector<vl> vvl; //vector of vectors
#define X first
#define Y second
#define mp(a, b) make_pair((a), (b))
#define REP(a, b) for (lo i = (a); i < (lo)b; i++) //no need to declare variable i
#define REPE(a, b, c, d) REP(a, b) \
for (lo j = (c); j < (lo)d; j++)                        //no need to declare vaiables i,j
#define REPV(a, b, c) for (lo(a) = b; (a) < (c); (a)++) //a is the variable
#define IREP(a, b) for (lo i = (a); i >= (b); i--)
#define IREPV(a, b, c) for (lo(a) = b; (a) >= (c); (a)--)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define all(v) (v).begin(), (v).end()
#define TRV(a) for (auto &it : a)
#define INF 201010
#define MOD 2000000007
#define M 1000000007
#define BLOCK 300
#define CHECK_BIT(var, pos) ((var) & (1 << (pos)))
#define pb(a) push_back((a))
#define eps 1e-2
#define LOGN 9
#define PI acos(-1.0)

#if _DEBUG
#define debug(x) cout << #x << "=" << x << endl
#define debug2(x, y) cout << #x << "=" << x << " " << #y << "=" << y << endl;
#define debug3(x, y, z) cout << #x << "=" << x << " " << #y << "=" << y << " " << #z << "=" << z << endl;
#define debug4(x, y, z, w) cout << #x << "=" << x << " " << #y << "=" << y << " " << #z << "=" << z << " " << #w << "=" << w << endl;
#define debug5(x, y, z, w, t)      \
    cout << #x << "=" << x << " "; \
    debug4(y, z, w, t);
#define debug6(p, x, y, z, w, t)                            \
    cout << #p << " " << p << " " << #x << "=" << x << " "; \
    debug4(y, z, w, t);
#define debug7(o, p, x, y, z, w, t) \
    cout << #o << " " << o << " ";  \
    debug6(p, x, y, z, w, t);
#define wait  \
    int xxxx; \
    cin >> xxxx;
#define derr(x) cerr << #x << "=" << x << endl;
#define derr2(x, y) cerr << #x << "=" << x << " " << #y << "=" << y << endl;
#define derr3(x, y, z) cerr << #x << "=" << x << " " << #y << "=" << y << " " << #z << "=" << z << endl;
#define derr4(x, y, z, w) cerr << #x << "=" << x << " " << #y << "=" << y << " " << #z << "=" << z << " " << #w << "=" << w << endl;
#define derr5(x, y, z, w, t)       \
    cerr << #x << "=" << x << " "; \
    derr4(y, z, w, t);
#define derr6(p, x, y, z, w, t)                             \
    cerr << #p << " " << p << " " << #x << "=" << x << " "; \
    derr4(y, z, w, t);
#define derr7(o, p, x, y, z, w, t) \
    cerr << #o << " " << o << " "; \
    derr6(p, x, y, z, w, t);

#else
#define debug(x) ;
#define debug2(x, y) ;
#define debug3(x, y, z) ;
#define debug4(x, y, z, q) ;
#define debug5(x, y, z, r, t) ;
#define debug6(x, y, z, r, t, s) ;
#define debug7(x, y, z, r, t, s, u) ;
#define wait ;
#define derr(x) ;
#define derr2(x, y) ;
#define derr3(x, y, z) ;
#define derr4(x, y, z, q) ;
#define derr5(x, y, z, r, t) ;
#define derr6(x, y, z, r, t, s) ;
#define derr7(x, y, z, r, t, f, u) ;
#endif

#define print_matrix(a, n, m) \
    REPE(0, n, 0, m) { cout << (a)[i][j] << ((j == m - 1) ? '\n' : ' '); }
#define present(container, element) (container.find(element) != container.end())
#define endl "\n"
template <typename T>
ostream &operator<<(ostream &o, vector<T> v)
{
    if (v.size() > 0)
        o << v[0];
    for (unsigned i = 1; i < v.size(); i++)
        o << " " << v[i];
    return o << " ";
}
template <typename U, typename V>
ostream &operator<<(ostream &o, pair<U, V> p)
{
    return o << "(" << p.first << ", " << p.second << ") ";
}
template <typename T>
istream &operator>>(istream &in, vector<T> &v)
{
    for (unsigned i = 0; i < v.size(); i++)
        in >> v[i];
    return in;
}
template <typename T>
istream &operator>>(istream &in, pair<T, T> &p)
{
    in >> p.X;
    in >> p.Y;
    return in;
}
template <typename T>
ostream &operator<<(ostream &o, set<T> v)
{
    TRV(v)
        o << it << " ";
    return o << endl;
}
template <typename T, typename U>
ostream &operator<<(ostream &o, map<T, U> v)
{
    TRV(v)
        o << it << " ";
    return o << endl;
}
struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
struct node
{
    lo best;
    lo mn[LOGN];
    node()
    {
        best = MOD;
        REP(0, LOGN)
        mn[i] = MOD;
    }
    lo &operator[](lo x)
    {
        return mn[x];
    }
};

vl a(INF);
vector<node> t(4 * INF);

void update(node &t, lo val)
{
    lo x = val;
    REP(0, LOGN)
    {
        if (x % 10 != 0)
            t[i] = min(t[i], val);
        x /= 10;
    }
}

node merge(node &a, node &b)
{
    node c;
    c.best = min(a.best, b.best);
    REP(0, LOGN)
    {
        c[i] = min(a[i], b[i]);
        if (a[i] != MOD and b[i] != MOD)
            c.best = min(c.best, a[i] + b[i]);
    }
    return c;
}

void build(lo v, lo l, lo r)
{
    if (l == r)
    {
        t[v] = node();
        update(t[v], a[l]);
        return;
    }
    lo m = (l + r) / 2;
    build(2 * v + 1, l, m);
    build(2 * v + 2, m + 1, r);
    t[v] = merge(t[2 * v + 1], t[2 * v + 2]);
}

void update(lo v, lo l, lo r, lo pos, lo val)
{
    if (l == r)
    {
        t[v] = node();
        update(t[v], val);
        return;
    }
    lo m = (l + r) / 2;
    if (pos <= m)
        update(2 * v + 1, l, m, pos, val);
    else
        update(2 * v + 2, m + 1, r, pos, val);

    t[v] = merge(t[2 * v + 1], t[2 * v + 2]);
}

node get(lo v, lo l, lo r, lo L, lo R)
{
    if (R < l or r < L)
        return node();
    if (l >= L and r <= R)
    {
        return t[v];
    }
    lo m = (l + r) / 2;
    node ln = get(2 * v + 1, l, m, L, R);
    node rn = get(2 * v + 2, m + 1, r, L, R);
    return merge(ln, rn);
}

int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(20);
    lo n, m;
    cin >> n >> m;
    REP(0, n)
        cin >> a[i];
    build(0, 0, n - 1);
    REP(0, m)
    {
        lo t, x, y;
        cin >> t >> x >> y;
        x--;
        y--;
        if (t == 1)
            update(0, 0, n - 1, x, y + 1);
        else
        {
            auto res = get(0, 0, n - 1, x, y).best;
            cout << (res == MOD ? -1 : res) << endl;
        }
    }
    return 0;
}
