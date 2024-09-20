#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;
// best on dp on trees;
int aa = -1e9;

void dfs(int node, int par, vector<int> adj[], vector<int>& ans) {
    for (auto it : adj[node]) {
        if (it != par) {
            dfs(it, node, adj, ans);
        }
    }
    
    int h1 = 0, h2 = 0;
    for (auto tt : adj[node]) {
        if (tt != par) {
            if (h1 <= 1 + ans[tt]) {
                h2 = h1;
                h1 = ans[tt] + 1;
            } else {
                h2 = max(h2, ans[tt] + 1);
            }
        }
    }
    aa = max(aa, h1 + h2);
    ans[node] = h1;
}

int main() {
    int n;
    cin >> n;
    vector<int> ans(n + 1, 0);
    vector<int> adj[n + 1];
    
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    dfs(1, -1, adj, ans);
    cout << aa << endl;

    return 0;
}
