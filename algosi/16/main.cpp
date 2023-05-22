
#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> parse_graph(int n, const vector<vector<int>>& graph){
    vector<vector<int>> new_graph(graph.size(), vector<int>(graph.size(), 0));
    for (int i = 0; i < graph.size(); i++) {
        for (int j = 0; j < graph.size(); j++) {
            if(graph[i][j]<=n & graph[i][j]!=0)  {new_graph[i][j]=1;   
            }
        }
    }
    return new_graph;
}

void DFS(const vector<vector<int>>& graph, int v, vector<bool>& visited) {
    visited[v] = true;
    for (int i = 0; i < graph[v].size(); ++i) {
        if (graph[v][i] && !visited[i]) {
            DFS(graph, i, visited);
        }
    }
}

bool isStronglyConnected(const vector<vector<int>>& graph) {
    int n = graph.size();
    vector<bool> visited(n, false);

    DFS(graph, 0, visited);
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            return false;
        }
    }

    visited = vector<bool>(n, false);
    vector<vector<int>> transposed_graph(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            transposed_graph[i][j] = graph[j][i];
        }
    }

    DFS(transposed_graph, 0, visited);
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            return false;
        }
    }

    return true;
}


int main() {
    int maxFuel=0;
    int n;
    cin >> n;
    vector<vector<int>> graph1(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph1[i][j];
            maxFuel = max(maxFuel, graph1[i][j]);
        }
    }



    int left =0;
    int right=maxFuel;
    while (left < right) {
        int mid = left + (right - left) / 2;
        vector<vector<int>> parsed_graph=parse_graph(mid, graph1);
        if (isStronglyConnected(parsed_graph)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    cout << left << endl;


    return 0;
}

