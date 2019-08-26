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
#define INF 500010
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
// lo min_distance(vl &free_columns, lo start, lo des)
// {
//     auto it = lower_bound(all(free_columns), start);
//     bool res = true;
//     lo ans = LLONG_MAX;
//     lo other = 0;
//     if (*it != start)
//     {
//         if (it != free_columns.begin())
//             it--;
//         else
//             res = false;
//     }
//     if (res)
//     {
//         other = (*it);
//         ans = start - (*it);
//         ans += abs(des - (*it));
//     }
//     it = upper_bound(all(free_columns), des);
//     if (it != free_columns.end())
//     {
//         if( ans > (*it) - start + abs((*it) - des))other = (*it);
//     }
//     return other;
//     // return {ans, other};
// }
lo min_distance(vl &left_column, vl &right_column, lo start, lo des){
    lo ans=LLONG_MAX, rans = LLONG_MAX;
    if(left_column[start]!=-1){
        ans = start - left_column[start] + abs(left_column[start] - des);
    }
    if(right_column[start != -1]){
       rans = right_column[start] - start + abs(right_column[start] - des);
    }
    derr4(start, des, ans, rans);
    return min(ans, rans);
}
int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(20);
    lo n, m, k, q;
    cin >> n >> m >> k >> q;
    vl a[n];
    REP(0, k)
    {
        lo x, y;
        cin >> x >> y;
        x--;
        y--;
        a[x].pb(y);
    }
    lo last_row = 0;
    REP(0, n)
    {
        sort(all(a[i]));
        if (!a[i].empty())
            last_row = i;
    }
    vl left_column(m,-1), right_column(m,m);
    REP(0, q)
    {
        lo x;
        cin >> x;
        left_column[x - 1] = x - 1;
        right_column[x - 1] = x - 1;
    }
    lo l_index, r_index;
    lo l_cost, r_cost;
    if (a[0].size() != 0)
    {
        if (a[0].size() == 1)
        {
            l_index = r_index = a[0][0];
            l_cost = r_cost = a[0][0];
        }
        else
        {
            l_index = a[0][0];
            r_index = a[0].back();
            r_cost = a[0].back();
            l_cost = r_cost + a[0].back() - a[0][0];
        }
    }
    else
    {
        l_index = r_index = 0;
        l_cost = r_cost = 0;
    }
    for(int i = 1; i < m ;i++)left_column[i] = max(left_column[i-1],left_column[i] );
    for(int i = m-2; i >= 0 ;i--)right_column[i] = min(right_column[i+1],right_column[i] );
    REP(0,m)if(right_column[i]==m)right_column[i] = -1;
    derr2(left_column, right_column);
    derr2(l_cost, l_index);
    REP(1, n)
    {
        if (a[i].empty())
        {
            continue;
        }
        else 
        {
            lo l_t = min(min_distance(left_column, right_column, l_index, a[i][0]) + l_cost + 2 * max(0LL, a[i].back() - max(l_index, a[i][0])),
                         min_distance(left_column, right_column, r_index, a[i][0]) + r_cost + 2 * max(0LL, a[i].back() - max(r_index, a[i][0])));
            lo r_t = min(min_distance(left_column, right_column, l_index, a[i].back()) + l_cost + 2 * max(0LL, l_index - min(a[i].back(), l_index)),
                         min_distance(left_column, right_column, r_index, a[i].back()) + r_cost + 2 * max(0LL, r_index - min(r_index, a[i].back())));
            l_index = a[i][0];
            r_index = a[i].back();
            l_cost = l_t;
            r_cost = r_t;
            // lo r_t = min(min_distance(left_column, right_column, l_index, a[i][0]) + l_cost ,
            //              (min_distance(left_column, right_column, r_index, a[i][0]) + r_cost ));
            // lo l_t = min(min_distance(left_column, right_column, l_index, a[i].back()) + l_cost,
            //              (min_distance(left_column, right_column, r_index, a[i].back()) + r_cost));
            // l_index = a[i][0];
            // r_index = a[i].back();
            // l_cost = l_t + a[i].back() - a[i][0];
            // r_cost = r_t + a[i].back() - a[i][0];
        }
        // else
        // {
        //     lo l_t = min(min_distance(free_columns, l_index, a[i][0]) + l_cost + 2 * max(0LL, a[i].back() - l_index),
        //                  min_distance(free_columns, a[i][0], r_index) + r_cost + 2 * max(0LL, a[i].back() - r_index));
        //     lo r_t = min(min_distance(free_columns, l_index, a[i].back()) + l_cost + 2 * max(0LL, l_index - a[i][0]),
        //                  min_distance(free_columns, a[i].back(), r_index) + r_cost + 2 * max(0LL, r_index - a[i][0]));
        //     l_index = a[i][0];
        //     r_index = a[i].back();
        //     l_cost = l_t;
        //     r_cost = r_t;
        // }
        derr5(i, l_index, l_cost, r_index, r_cost);
    }
    cout << min(l_cost, r_cost) + last_row;
    return 0;
}
