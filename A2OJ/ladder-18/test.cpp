#include <bits/stdc++.h>
using namespace std;  
const int maxp = 16;
const int maxn = 105;
const int maxnum = 58;
const int INF = 0x3f3f3f3f;
int n,m;  
int ss[maxp]= {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};
int use[60]; 
int rec[maxn][1<<maxp];
int dp[maxn][1<<maxp];
int a[maxn];  
int ans[maxn];  
int main()  
{  
    scanf("%d",&n);
    for(int i=1; i<=n; i++) scanf("%d",&a[i]);  
    for (int i = 1; i <= maxnum; ++i)
    for (int j = 0; j < maxp; ++j)
    if (i % ss[j] == 0) use[i] |= 1 << j;
    memset(rec,-1,sizeof(rec));  
    memset(dp,63,sizeof(dp));  
    const int INF=dp[0][0];  
    dp[0][0]=0;  
    for (int i = 1; i <= n; ++i)
    for (int j = 0; j < 1<<maxp; ++j)
    for (int k = 1; k <= maxnum; ++k)
    if (dp[i - 1][j] != INF && (use[k] & j) == 0)
    {
    	int d = abs(a[i] - k);
    	if (dp[i][j | use[k]] > dp[i - 1][j] + d) dp[i][j | use[k]] = dp[i - 1][j] + d, rec[i][j | use[k]] = k;
	}
    int Min=INF,pl;  
    for (int j = 0; j < (1<< maxp); ++j)
    if (dp[n][j] < Min) Min = dp[n][j],pl = j;
    for (int i = n; i > 0; --i) {
        cout<<rec[i][pl]<<" "<<pl<<endl;
        ans[i] = rec[i][pl],pl ^= use[ans[i]];
    }
	for (int i = 1; i <= n; ++i) printf("%d ",ans[i]);
 
    return 0;  
}  