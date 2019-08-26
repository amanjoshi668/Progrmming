#include <bits/stdc++.h>
#include <unistd.h>
//#include <ext/pb_ds/assoc_container.hpp> // Common file
//#include <ext/pb_ds/tree_policy.hpp> // Including seg_tree_order_statistics_Node_update
#include <stdio.h>
#include <cassert>
using namespace std;
//using namespace __gnu_pbds;
/*
    TYPENAME
*/
typedef long long lo;
typedef long double ld;
#include <ctime>
typedef pair<lo, lo> ll; //pair
typedef vector<lo> vl;   //vector of long
typedef vector<ll> vll;  //vector of pair
typedef priority_queue<lo> p_q;
typedef vector<vl> vvl; //vector of vectors

/*
    MACROS
*/
#define X first
#define Y second
#define mp(a, b) make_pair((a), (b))
#define REP(a, b) for (lo i = (a); i < (lo)b; i++) //no need to declare variable i
#define REPE(a, b, c, d) \
    REP(a, b)            \
    for (lo j = (c); j < (lo)d; j++)                    //no need to declare vaiables i,j
#define REPV(a, b, c) for (lo(a) = b; (a) < (c); (a)++) //a is the variable
#define IREP(a, b) for (lo i = (a); i >= (b); i--)
#define IREPV(a, b, c) for (lo(a) = b; (a) >= (c); (a)--)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define all(v) (v).begin(), (v).end()
#define TRV(a) for (auto &it : a)
#define INF 500
#define MOD 1000000007
#define M 1000000007
#define BLOCK 300
#define CHECK_BIT(var, pos) ((var) & (1 << (pos)))
#define pb(a) push_back((a))
#define eps 1e-2
#define PI acos(-1.0)

/*
    DEBUG STATEMENTS
*/
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

/*
    print statements for data types
*/

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
/*
    COMMON HELPER FUNCTIONS
*/
template <typename T>
T &&vmin(T &&val)
{
    return std::forward<T>(val);
}

template <typename T0, typename T1, typename... Ts>
auto vmin(T0 &&val1, T1 &&val2, Ts &&... vs)
{
    return (val1 < val2) ? vmin(val1, std::forward<Ts>(vs)...) : vmin(val2, std::forward<Ts>(vs)...);
}
template <typename T>
T &&vmax(T &&val)
{
    return std::forward<T>(val);
}

template <typename T0, typename T1, typename... Ts>
auto vmax(T0 &&val1, T1 &&val2, Ts &&... vs)
{
    return (val1 > val2) ? vmax(val1, std::forward<Ts>(vs)...) : vmax(val2, std::forward<Ts>(vs)...);
}
template <typename T, typename U>
void add(T &a, U b)
{
    a += b;
    if (a > MOD)
        a -= MOD;
    if (a > MOD)
        a %= MOD;
}
template <typename T, typename U>
void mul(T a, U b)
{
    a *= b;
    return a % MOD;
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
lo binary_minus(lo index, lo n, vl &a)
{
    lo x = a[index];
    lo l = index + 1;
    lo r = n - 1;
    index = n;
    while (l <= r)
    {
        lo mid = (l + r) / 2;
        lo y = a[mid];
        if (abs(y) <= abs(x + y) and abs(x) <= abs(x + y))
        {
            index = min(index, mid);
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    return index;
}
lo binary_plus(lo index, lo n, vl &a)
{
    lo x = a[index];
    lo l = index + 1;
    lo r = n - 1;
    while (l <= r)
    {
        lo mid = (l + r) / 2;
        lo y = a[mid];
        if (abs(y) >= abs(x - y) and abs(x) >= abs(x - y))
        {
            index = max(index, mid);
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    return index;
}
struct node
{
    lo x;
    lo o;
    lo X;
    lo z;
    node()
    {
        this->x = this->o = this->X = this->z = 0;
    }
};
ostream &operator<<(ostream &o, node &a)
{
    return o << "one = " << a.o << ", zero = " << a.z << " x = " << a.x << " x_bar = " << a.X << endl;
}
node merge(node a, node b, char oper)
{
    node res;
    // debug2(a, b);
    res.o = res.z = res.x = res.X = MOD;
    res.z = min(a.z + b.z + (oper != '|'), res.z);
    res.o = min(vmin(a.o + vmin(b.o, b.z, b.x, b.X), b.o + vmin(a.o, a.z, a.x, a.X), a.x + b.X, a.X + b.x) + (oper != '|'), res.o);
    res.x = min(vmin(a.x + b.z, a.x + b.x, a.z + b.x) + (oper != '|'), res.x);
    res.X = min(vmin(a.X + b.z, a.X + b.X, a.z + b.X) + (oper != '|'), res.X);

    res.z = min(vmin(a.z + vmin(b.o, b.z, b.x, b.X), b.z + vmin(a.o, a.z, a.x, a.X), a.x + b.X, a.X + b.x) + (oper != '&'), res.z);
    res.o = min(res.o, a.o + b.o + (oper != '&'));
    res.x = vmin(res.x, vmin(a.x + b.o, a.x + b.x, a.o + b.x) + (oper != '&'));
    res.X = vmin(res.X, vmin(a.X + b.o, a.X + b.X, a.o + b.X) + (oper != '&'));

    res.z = min(res.z, vmin(a.o + b.o, a.z + b.z, a.x + b.x, a.X + b.X) + (oper != '^'));
    res.o = min(res.o, vmin(a.o + b.z, a.z + b.o, a.x + b.X, a.X + b.x) + (oper != '^'));
    res.x = min(res.x, vmin(a.z + b.x, a.x + b.z, a.o + b.X, a.X + b.o) + (oper != '^'));
    res.X = min(res.X, vmin(a.x + b.o, a.X + b.z, a.o + b.x, a.z + b.X) + (oper != '^'));
    // debug(res);
    return res;
}
vl bracket(INF, -1);
node fun(string &a, lo l, lo r)
{
    // debug2(l, r);
    node res, res1, res2;
    if (l > r or r >= a.length())
        return res;
    lo end_l = l + 2;
    if (a[l] == '(')
    {
        res1 = fun(a, l + 1, bracket[l] - 1);
        end_l = bracket[l] + 2;
    }
    else
    {
        if (a[l] == '0')
        {
            res1.x++;
            res1.X++;
            res1.o++;
        }
        if (a[l] == '1')
        {
            res1.x++;
            res1.X++;
            res1.z++;
        }
        if (a[l] == 'x')
        {
            res1.z++;
            res1.X++;
            res1.o++;
        }
        if (a[l] == 'X')
        {
            res1.x++;
            res1.z++;
            res1.o++;
        }
    }
    if (end_l > r)
        return res1;
    auto oper = a[end_l - 1];
    if (a[end_l] == '(')
    {
        res2 = fun(a, end_l + 1, r - 1);
    }
    else
    {
        if (a[end_l] == '0')
        {
            res2.x++;
            res2.X++;
            res2.o++;
        }
        if (a[end_l] == '1')
        {
            res2.x++;
            res2.X++;
            res2.z++;
        }
        if (a[end_l] == 'x')
        {
            res2.z++;
            res2.X++;
            res2.o++;
        }
        if (a[end_l] == 'X')
        {
            res2.x++;
            res2.z++;
            res2.o++;
        }
    }
    return merge(res1, res2, oper);
}
int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(20);
    lo T;
    cin >> T;
    REPV(t, 1, T + 1)
    {
        string a;
        cin >> a;
        stack<lo> s;
        lo n = a.length();
        REP(0, n)
        {
            if (a[i] == '(')
            {
                s.push(i);
            }
            else if (a[i] == ')')
            {
                auto x = s.top();
                s.pop();
                bracket[x] = i;
            }
        }
        auto ans = fun(a, 0, n - 1);
        cout << "Case #" << t << ": " << min(ans.o, ans.z);
        cout << endl;
        fill(all(bracket), -1);
    }
    return 0;
}
