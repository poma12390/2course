#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;

const int INF = 1e9 + 7;

struct Node {
    int x, y, dist;
    string path;
    Node(int x, int y, int dist, string path) : x(x), y(y), dist(dist), path(path) {}

    bool operator>(const Node& node) const {
        return dist > node.dist;
    }
};

bool isValid(int x, int y, int n, int m, vector<string>& world_map) {
    return (x >= 0 && x < n && y >= 0 && y < m && world_map[x][y] != '#');
}

int main() {
    int n, m;
    cin >> n >> m;

    int x_start, y_start;
    cin >> x_start >> y_start;
    --x_start, --y_start;

    int x_end, y_end;
    cin >> x_end >> y_end;
    --x_end, --y_end;

    vector<string> world_map(n);
    for(int i = 0; i < n; ++i)
        cin >> world_map[i];

    vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    priority_queue<Node, vector<Node>, greater<Node>> q;
    q.push(Node(x_start, y_start, 0, ""));

    string res_path = "";
    int res_dist = INF;

    while(!q.empty()) {
        Node curr = q.top();
        q.pop();

        if(curr.x == x_end && curr.y == y_end) {
            res_dist = curr.dist;
            res_path = curr.path;
            break;
        }

        for(int i = 0; i < 4; ++i) {
            int nx = curr.x + dir[i].first;
            int ny = curr.y + dir[i].second;

            if(isValid(nx, ny, n, m, world_map)) {
                int cost = curr.dist + (world_map[nx][ny] == 'W' ? 2 : 1);
                string new_path = curr.path;

                if(i == 0) new_path += 'E';
                else if(i == 1) new_path += 'W';
                else if(i == 2) new_path += 'S';
                else new_path += 'N';

                q.push(Node(nx, ny, cost, new_path));
            }
        }
    }

    if(res_dist == INF) {
        cout << -1 << "\n";
    } else {
        cout << res_dist << "\n";
        cout << res_path << "\n";
    }

    return 0;
}
