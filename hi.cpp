#include <bits/stdc++.h>
using namespace std;

int ann = 0;

void dfs(int node, vector<int> adj[], int par, vector<int> &ans)
{
    ans[node] = 0;
    int max1 = 0, max2 = 0;

    for (auto it : adj[node])
    {
        if (it != par)
        {
            dfs(it, adj, node, ans);
            int curr = ans[it] + 1;
            ans[node] = max(ans[node], curr);

            if (curr >= max1)
            {
                max2 = max1;
                max1 = curr;
            }
            else if (curr > max2)
            {
                max2 = curr;
            }
        }
    }

    int dia_node = max1 + max2;
    ann = max(ann, dia_node);
}

int main()
{
    int n;
    cin >> n;

    vector<int> adj[n + 1];

    
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> ans(n + 1, 0);

    dfs(1, adj, -1, ans);

    cout << ann << endl;
    return 0;
}