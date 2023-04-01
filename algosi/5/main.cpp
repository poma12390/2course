#include <iostream>
#include <vector>
#include <algorithm>

bool check(const std::vector<int>& places, int min_distance, int cows) {
    int count = 1;
    int last_position = places[0];
    for (int i = 1; i < places.size(); ++i) {
        if (places[i] - last_position >= min_distance) {
            last_position = places[i];
            ++count;
            if (count >= cows) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n, k, left, right;
    std::cin >> n >> k;
    std::vector<int> places(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> places[i];
    }

    left = 0;
    right = places[n - 1] - places[0] + 1;
    while (right - left > 1) {
        int mid = left + (right - left) / 2;
        if (check(places, mid, k)) {
            left = mid;
        } else {
            right = mid;
        }
    }

    std::cout << left << std::endl;

    return 0;
}
