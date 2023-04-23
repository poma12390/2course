#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int main() {
int n, k, p;
cin >> n >> k >> p;
vector<int> toys(p);
for (int i = 0; i < p; ++i) {
cin >> toys[i];
}
set<int> floor_toys;
map<int, int> toy_positions;
for (int i = 0; i < p; ++i) {
    toy_positions[toys[i]] = i;
}

int operations = 0;

for (int i = 0; i < p; ++i) {
    int toy = toys[i];

    if (floor_toys.count(toy)) {
        toy_positions.erase(toy);
        continue;
    }

    if (floor_toys.size() == k) {
        int max_position = -1;
        int toy_to_remove = -1;
        for (const int& t : floor_toys) {
            if (toy_positions.count(t)) {
                if (toy_positions[t] > max_position) {
                    max_position = toy_positions[t];
                    toy_to_remove = t;
                }
            } else {
                toy_to_remove = t;
                break;
            }
        }
        floor_toys.erase(toy_to_remove);
        toy_positions.erase(toy_to_remove);
    }

    floor_toys.insert(toy);
    toy_positions.erase(toy);
    operations++;
}

cout << operations << endl;

return 0;
}