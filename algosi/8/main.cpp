#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, k,result,count;
    std::cin >> n >> k;

    std::vector<int> prices(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> prices[i];
    }

    std::sort(prices.begin(), prices.end());

    result = count=0;
    for (int i=n-1; i>-1; i--) (count == k - 1) ? count = 0 : (result += prices[i], count++);

    std::cout << result << std::endl;

    return 0;
}
