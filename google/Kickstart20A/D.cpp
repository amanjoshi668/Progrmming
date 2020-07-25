#include <bits/stdc++.h>

using namespace std;
typedef long long lo;

lo K;
struct node
{
    node *p[26];
    int count;
    int depth;
    set<lo> index;
    pair<lo, lo> max_child;
    node()
    {
        count = 0;
        depth = 0;
        max_child = make_pair(-1, -1);
        for(int i =0 ; i < 26; i++)
            p[i] = NULL;
    }
};

class trie
{
public:
    node *root;
    trie()
    {
        root = new node();
    }

    void insert(node *n, string &s, int i, int in)
    {
        n->count++;
        n->index.insert(in);
        n->depth = i; 
        if (n->count == K)
        {
            n->max_child = {-1, i};
        }
        if (s.length() == i)
            return ;

        lo child_index = s[i] - 'A';
        if (n->p[child_index] == NULL)
        {
            n->p[child_index] = new node();
        }
        auto c = n->p[child_index];
        insert(c, s, i + 1, in);
        if (c->max_child.second > n->max_child.second)
            n->max_child = make_pair(child_index, c->max_child.second);
        return;
    }

    void del(node *n, string &s, int i, int in)
    {
        n->count--;
        n->index.erase(in);
        if (n->count == K-1)
        {
            n->max_child = {-1, -1};
        }
        if (s.length() == i)
            return;
        lo child_index = s[i] - 'A';
        auto c = n->p[child_index];
        del(c, s, i + 1, in);
        if (n->max_child.first == child_index)
            n->max_child = make_pair(child_index, c->max_child.second);
        for (int i = 0; i < 26; i++)
            if (n->p[i] != NULL)
                if (n->p[i]->max_child.second > n->max_child.second)
                    n->max_child = make_pair(i, n->p[i]->max_child.second);
        if (n->max_child.second == -1 and n->count >= K)
            n->max_child = make_pair(-1, n->depth);
        return;
    }

    pair<int, set<lo>> findSet(node *n)
    {
        pair<int, set<lo>> res;
        if (n->max_child.first == -1)
            res = make_pair(n->depth, n->index);
        else 
            res = findSet(n->p[n->max_child.first]);
        return res;
    }
};
int main(int argc, char *argv[])
{
    lo T;
    cin >> T;
    for (int t = 1; t < T + 1; t++)
    {
        lo n;
        cin >> n >> K;
        vector<string> S(n);
        trie Tr;
        for (int i = 0; i < n; i++)
        {
            cin >> S[i];
            Tr.insert(Tr.root, S[i], 0, i);
        }
        auto ans = 0;
        int times = n / K;
        while (times--)
        {
            auto res = Tr.findSet(Tr.root);
            ans += res.first;
            lo counter = 0;
            for (auto it : res.second)
            {
                Tr.del(Tr.root, S[it], 0, it);
                counter++;
                if (counter == K)
                    break;
            }
        }
        cout << "Case #" << t << ": " << ans << endl;
    }
    return 0;
}
