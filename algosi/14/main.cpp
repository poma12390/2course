#include<bits/stdc++.h>
using namespace std;

int dfs(int v, vector<int> &visited, vector<int> &keyInPiggy, int cycle) {
    if (visited[v] == 0 & visited[keyInPiggy[v]] == 0) {  
        cycle++;
        visited[v]=1;
        visited[keyInPiggy[v]]=2;
    }
    else if (visited[v] == 0 & visited[keyInPiggy[v]]!=3){
        cout << keyInPiggy[v] << " i" << endl;
        visited[v]=1;
        visited[keyInPiggy[v]]=3;
    }

    if (visited[keyInPiggy[v]] == 0)
        dfs(keyInPiggy[v], visited, keyInPiggy, 0);
    return cycle;
}

int main() {
 

    int n;
    cin >> n;

    vector<int> keyInPiggy(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> keyInPiggy[i];
    }

    vector<int> visited(n + 1, 0);
    int cycle = 0;
    for (int i = 1; i <= n; i++) {
        if (visited[i] == 0 | visited[keyInPiggy[i]] == 0){
            cycle =dfs(i, visited, keyInPiggy, cycle);
        }
        for(int j:visited){
            cout << j << " ";
        }
        cout << endl;
    }

    cout << cycle << "\n";
    return 0;
}
