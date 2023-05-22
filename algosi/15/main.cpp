#include <iostream>
#include <vector>

using namespace std;

bool dfs(vector<int> &group,vector<vector<int>> &g, int v, int c) {
    group[v] = c;
    for (int u : g[v]) {
        if (!group[u]) {
            if (!dfs(group, g, u, 3 - c)) {
                return false;
            }
        } else if (group[u] == c) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> group(n+1);
    vector<vector<int>> g(n+1);

    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i) {
        if (!group[i] && !dfs(group, g, i, 1)) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}

