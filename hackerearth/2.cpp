#include <bits/stdc++.h>
using namespace std;
//using namespace __gnu_pbds;
typedef long long lo;
typedef vector<lo> vl;
#define REP(a, b) for (lo i = (a); i < (lo)b; i++) //no need to declare variable i
#define REPE(a, b, c, d) \
    REP(a, b)            \
    for (lo j = (c); j < (lo)d; j++)                    //no need to declare vaiables i,j
#define REPV(a, b, c) for (lo(a) = b; (a) < (c); (a)++) //a is the variable
vl dx = {0, 0, -1, 1};
vl dy = {-1, 1, 0, 0};
inline bool correct(lo nx, lo ny, lo n, lo m)
{
    return (nx >= 0 && nx < n && ny >= 0 && ny < m);
}
void dfs(lo x, lo y, vector<string> &A, lo n, lo m)
{
    A[x][y] = 'v';
    REP(0, 4)
    {
        lo nx = x + dx[i];
        lo ny = y + dy[i];
        if (correct(nx, ny, n, m))
            if (A[nx][ny] == 'g')
                dfs(nx, ny, A, n, m);
    }
}
bool connected(vector<string> &A, lo n, lo m)
{
    REPE(0, n, 0, m)
    if (A[i][j] == 'g')
    {
        dfs(i, j, A, n, m);
        break;
    }
    REPE(0, n, 0, m)
    if (A[i][j] == 'g')
        return false;
    return true;
}
int main(int argc, char *argv[])
{
    // std::ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    // cout.precision(20);
    lo n, m;
    lo index = 0;
    cin >> n >> m;
    vector<string> A(n);
    REP(0, n)
        cin >> A[i];
    lo res = 4;
    REPE(0, n, 0, m)
    if (A[i][j] == 'g')
    {
        lo x = 0;
        REPV(k, 0, 4)
        {
            lo nx = i + dx[k];
            lo ny = j + dy[k];
            if (correct(nx, ny, n, m))
                if (A[nx][ny] == 'g')
                    x++;
        }
        // cout << i << " " << j << " " << x << endl;
        res = min(res, x);
    }
    if (!connected(A, n, m))
        res = 0;
    cout << res << endl;
    return 0;
}
