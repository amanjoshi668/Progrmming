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
#define MOD2 1000000009
#define BLOCK 300
#define CHECK_BIT(var, pos) ((var) & (1 << (pos)))
#define pb(a) push_back((a))
#define eps 1e-2
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
lo checkpoint_counter = 0;
#define checkpoint cerr << "At checkpoint : " << checkpoint_counter++ << endl;

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
#define checkpoint ;
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
vl dx = {0, 1, 0, -1};
vl dy = {1, 0, -1, 0};
vector<char> dir = {'R', 'D', 'L', 'U'};
ll a[1001][1001];
lo n;
string s[1001];
bool valid;
void dfs(lo x, lo y, lo sx, lo sy){
    // debug2(x, y);
    REP(0, 4){
        lo nx = x+dx[i];
        lo ny = y+dy[i];
        if(!(correct(nx, ny, n, n)))
            continue;
        if(nx == sx and ny == sy){
            s[x][y] = dir[i];
            valid = true;
            return;
        }
        if(a[nx][ny] == make_pair(-2LL, -2LL) and s[nx][ny] == '-'){
            s[x][y] = dir[i];
            debug5(x, y, nx, ny, dir[i]);
            dfs(nx, ny, sx, sy);
            return;
        }
    }
}
void dfs2(lo x, lo y, lo sx, lo sy){
    debug4(x+1, y+1, sx+1, sy+1);
    REP(0, 4){
        lo nx = x+dx[i];
        lo ny = y+dy[i];
        if(!(correct(nx, ny, n, n)))
            continue;
        if(a[nx][ny] == make_pair(sx, sy) and s[nx][ny] == '-'){
            int f = i-2;
            if(f<0)f+=4;
            s[nx][ny] = dir[f];
            dfs2(nx, ny, sx, sy);
        }
    }
}
int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(20);
    cin >> n;
    REPE(0, n, 0, n){
        cin >> a[i][j];
        a[i][j].X--;a[i][j].Y--;
    }
    string temp = string(n, '-');
    REP(0, n)s[i] = temp;
    REPE(0, n, 0, n){
        debug2(a[i][j], s[i][j]);
        if(a[i][j] == make_pair(-2LL , -2LL) and s[i][j] == '-'){
            debug("one");
            valid = false;
            dfs(i, j, i, j);
            if(!valid){
                cout <<"INVALID"<<endl;
                return 0;
            }
        }
        else if(a[i][j] == make_pair(i, j) and s[i][j] == '-'){
            debug("two");
            s[i][j] = 'X';
            dfs2(i, j, i, j);
        }
    }
    valid = true;
    REPE(0, n, 0, n)if(s[i][j] == '-')valid = false;
    if(!valid){
                cout <<"INVALID"<<endl;
                return 0;
            }
    cout << "VALID"<<endl;
    REP(0, n)cout << s[i] << endl;
    return 0;
}
/*
4
2 3 2 3 2 3 2 3
4 1 4 1 2 3 2 3
4 1 4 1 3 3 2 3
4 1 4 1 2 3 2 3

4
1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 
4 4 4 4 4 4 4 4 
4 4 4 4 4 4 4 4

4
-1 -1 -1 -1 -1 -1 -1 -1 
-1 -1 -1 -1 -1 -1 -1 -1 
-1 -1 -1 -1 -1 -1 -1 -1 
-1 -1 -1 -1 -1 -1 -1 -1 
*/