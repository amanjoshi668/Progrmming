#include<bits/stdc++.h>
using namespace std;
typedef long long lo;
typedef vector<string> vs;
typedef pair<lo,lo> ll;//pair
typedef vector<lo> vl;  //vector of long
typedef vector<ll > vll;   //vector of pair
typedef priority_queue<lo>p_q;
#define CHECK_BIT(var,pos) ((var) & (1<<(pos)))
#define X first
#define Y second
#define mp(a,b) make_pair((a),(b))
#define REP(a,b) for(lo i=(a);i<(b);i++)//no need to declare variable i
#define REPE(a,b,c,d) REP(a,b)for(lo j=(c);j<(d);j++)//no need to declare vaiables i,j
#define REPV(a,b,c) for((a)=b;(a)<(c);(a)++)//a is the variable
#define IREP(a,b) for(lo i=(a);i>=(b);i--)
#define IREPV(a,b,c) for((a)=b;(a)>=(c);(a)--)
#define all(v) (v).begin(),(v).end()
#define TRvl(c) for (vl::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvll(c) for (vll::iterator it = (c).begin(); it != (c).end(); it++)
#define INF 2000000000
#define gc getchar_unlocked
#define pc putchar_unlocked
#define pb(a) push_back((a))
#define mod 1000000007

int main(){
    //lo i,j,k,l,m,n,t,te,_;
    
    lo n;
    string s;
    cin>>n>>s;
    set<char> S;
    vl count(26, 0);
    REP(0, s.length())count[s[i] - '0']++;
    REP(0, 10){
        count[i] %= 2;
        if(count[i])S.insert(i+'0');
        count[i] = 0;
    }
    lo ans = LLONG_MAX;
    lo l = 0;
    lo r = 0;
    lo mx = 0;
    // REP(0, 10)cout<<count[i]<<" ";
    // cout<<endl;
    while(true){
        if(S.find(s[r]) == S.end()){
            r++;
            if(r == s.length())break;
            continue;
        }
        lo x = s[r] - '0';
        count[x] ++;
        if(count[x] == 1){
            mx++;
        }
        if(mx == S.size()){
            // cout<<"here"<<endl;
            x = s[l] - '0';
            // cout<<"ghhghgh"<<endl;;
            while((S.find(s[l]) == S.end()) or count[x] > 1){
                if(S.find(s[l]) != S.end())count[x]--;
                    l++;
                    x = s[l] - '0';
                // cerr<<l<<endl;;
                if(l>r)break;
            }
            ans = min(ans, r-l);
        }
        r++;
        if(r == s.length())break;
    }
    cout<<ans;
    return 0;
}