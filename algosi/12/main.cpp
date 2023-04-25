#include <iostream>
#include <deque>
#include <vector>

using namespace std;

vector<int> min_in_window(int N, int K, const vector<int>& seq) {
    vector<int> min_values;
    deque<int> dq   ;

    for (int i = 0; i < N; ++i) {
        while (!dq.empty() && dq.back() > seq[i]) {
            dq.pop_back();
        }
        dq.push_back(seq[i]);

        if (i >= K - 1) {
            min_values.push_back(dq.front());
            if (seq[i - K + 1] == dq.front()) {
                dq.pop_front();
            }
        }
    }
    return min_values;
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> seq(N);
    for (int i = 0; i < N; ++i) {
        cin >> seq[i];
    }

    vector<int> min_values = min_in_window(N, K, seq);
    for (int val : min_values) {
        cout << val << " ";
    }

    return 0;
}
