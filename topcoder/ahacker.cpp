#include <bits/stdc++.h>
using namespace std;
typedef long long lo;
string fun(string a, string b)
{
    if (a.find(b) != string::npos)
        return a;
    string temp = "";
    for (int i = 0; i < b.length(); i++)
    {
        if (a.find(b.substr(i, b.length() - i)) == 0)
        {
            temp = b.substr(0, i) + a;
            cout<<temp<<"! ";
            return temp;
        }
        if(a.find(b.substr(0, b.length() - i - 1)) != string::npos)
        if (a.find(b.substr(0, b.length() - i - 1)) == a.length() - i);
        {
            temp = a + b.substr(b.length() - i - 1, i);
            cout<<"["<<a<<"%%%%"<<b<<"]";
            cout<<temp<<"@ ";
            return temp;
        }
    }
    return a + b;
}
int solve(const vector<int> &A) {
    int n = A.size();
    vector<vector<long long>> dp(2, vector<long long>(20100, 100));
    int offset = 10011;    
    dp[0][0 + offset] = 0;
    for(int x = 1; x<=n; x++){
        int i = x&1;
        int j = i^1;
        for(int sum = -10000; sum<=10000; sum++){
            dp[i][sum + A[x-1] + offset] = min(dp[j][sum + offset], dp[i][sum + A[x-1] + offset]);
            dp[i][sum - A[x-1] + offset] = min(dp[j][sum + offset] + 1, dp[i][sum - A[x-1] + offset]);
        }
        for(int sum = -10000; sum<=10000; sum++)dp[j][sum+offset] = 100;
        for(int j = -10; j<10; j++)cout<<dp[i][j+offset]<<"\t";
        cout<<endl;
    }
    int res = 0;
    for(int i=0;i<offset; i++){
        if(dp[n&1][offset + i] != INT_MAX)return dp[n&1][offset + i];
    }
}

int main()
{
    lo n;
    cin >> n;
    vector<int>A(n);
    for(int i=0;i<n; i++)cin>>A[i];
    cout<<solve(A);
    return 0;
}