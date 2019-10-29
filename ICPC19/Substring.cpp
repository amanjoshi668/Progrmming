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
#define INF 500010
#define MOD 1000000007
#define MOD2 1000000009
#define BLOCK 300
#define CHECK_BIT(var, pos) ((var) & (1 << (pos)))
#define pb(a) push_back((a))
#define eps 1e-2
#define PI acos(-1.0)

// #if _//debug
// #define //debug(x) cout << #x << "=" << x << endl
// #define //debug2(x, y) cout << #x << "=" << x << " " << #y << "=" << y << endl;
// #define //debug3(x, y, z) cout << #x << "=" << x << " " << #y << "=" << y << " " << #z << "=" << z << endl;
// #define //debug4(x, y, z, w) cout << #x << "=" << x << " " << #y << "=" << y << " " << #z << "=" << z << " " << #w << "=" << w << endl;
// #define //debug5(x, y, z, w, t)      \
//     cout << #x << "=" << x << " "; \
//     //debug4(y, z, w, t);
// #define //debug6(p, x, y, z, w, t)                            \
//     cout << #p << " " << p << " " << #x << "=" << x << " "; \
//     //debug4(y, z, w, t);
// #define //debug7(o, p, x, y, z, w, t) \
//     cout << #o << " " << o << " ";  \
//     //debug6(p, x, y, z, w, t);
// #define wait  \
//     int xxxx; \
//     cin >> xxxx;
// #define derr(x) cerr << #x << "=" << x << endl;
// #define derr2(x, y) cerr << #x << "=" << x << " " << #y << "=" << y << endl;
// #define derr3(x, y, z) cerr << #x << "=" << x << " " << #y << "=" << y << " " << #z << "=" << z << endl;
// #define derr4(x, y, z, w) cerr << #x << "=" << x << " " << #y << "=" << y << " " << #z << "=" << z << " " << #w << "=" << w << endl;
// #define derr5(x, y, z, w, t)       \
//     cerr << #x << "=" << x << " "; \
//     derr4(y, z, w, t);
// #define derr6(p, x, y, z, w, t)                             \
//     cerr << #p << " " << p << " " << #x << "=" << x << " "; \
//     derr4(y, z, w, t);
// #define derr7(o, p, x, y, z, w, t) \
//     cerr << #o << " " << o << " "; \
//     derr6(p, x, y, z, w, t);
// lo checkpoint_counter=0;
// #define checkpoint cerr << "At checkpoint : " << checkpoint_counter++ << endl;

// // #else
// // #define //debug(x) ;
// // #define //debug2(x, y) ;
// // #define //debug3(x, y, z) ;
// // #define //debug4(x, y, z, q) ;
// // #define //debug5(x, y, z, r, t) ;
// // #define //debug6(x, y, z, r, t, s) ;
// // #define //debug7(x, y, z, r, t, s, u) ;
// // #define wait ;
// // #define derr(x) ;
// // #define derr2(x, y) ;
// // #define derr3(x, y, z) ;
// // #define derr4(x, y, z, q) ;
// // #define derr5(x, y, z, r, t) ;
// // #define derr6(x, y, z, r, t, s) ;
// // #define derr7(x, y, z, r, t, f, u) ;
// #define checkpoint ;
// #endif

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
vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}
bool ispalin(string &a, lo l, lo r){
    // lo l = 0;
    bool ans = true;
    while(l<r){
        if(a[l] != a[r])return false;
        l++;
        r--;
    }
    return true;
}
lo fun(string a){
    lo ans = 0;
    lo n = a.length();
    REP(0, a.length())if(ispalin(a, 0, i))ans = i+1;
    IREP(a.length()-1, 0)if(ispalin(a, i, n-1))ans = max(ans, n-i);
    // //debug(ans);
    return a.length() - ans;
}
lo fun2(string a){
    lo ans = 0;
    //debug(a);
    lo n = a.length();
    IREP(a.length()-1, 0)if(ispalin(a, i, n-1))ans = max(ans, n-i);
    //debug(ans);
    return a.length() - ans;
}
int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(20);
    lo t;
    cin>>t;
    while(t--){
        string a, b;
        cin>>a>>b;
        lo ans = LLONG_MAX;
        REPV(xxxx, 0, 2){
            //debug(xxxx);
            swap(a, b);
            auto find = a.find(b);
            lo n = a.length();
            lo m = b.length();
            //debug2(a, b);
            if(find != std::string::npos){
                // cout<<"HES"<<endl;
                ans = min(ans, fun(a) + n);
            }
            else{
                reverse(all(b));
                lo x = 0;
                while(a[x] == b[x] and x<a.length() and x<b.length())x++;
                if(x){
                    lo at = fun2(a.substr(x, a.length() - x));
                    lo bt = fun2(b.substr(x, b.length() - x));
                    // cout<<"x"<<x<<" "<<at<<" "<<bt<<endl;
                    ans = min(ans, at + bt + n + m);
                }
                else{
                    ans = min(ans, fun2(a) + n + 2*m);
                    ans = min(ans, fun2(b) + n*2 + m);
                }
                reverse(all(b));
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
