#include <iostream>
#include <queue>
#include <string>

void balanceQueues(std::deque<int>& firstHalf, std::deque<int>& secondHalf) {
    if (firstHalf.size() < secondHalf.size()) {
        firstHalf.push_back(secondHalf.front());
        secondHalf.pop_front();
    } else if (firstHalf.size() > secondHalf.size() + 1) {
        secondHalf.push_front(firstHalf.back());
        firstHalf.pop_back();
    }
}

int main() {
    int n;
    std::cin >> n;

    std::deque<int> firstHalf, secondHalf;
    char command;
    int id;

    for (int i = 0; i < n; i++) {
        std::cin >> command;
        if (command == '+') {
            std::cin >> id;
            secondHalf.push_back(id);
            balanceQueues(firstHalf, secondHalf);
        } else if (command == '*') {
            std::cin >> id;
            firstHalf.push_back(id);
            balanceQueues(firstHalf, secondHalf);
        } else if (command == '-') {
            std::cout << firstHalf.front() << std::endl;
            firstHalf.pop_front();
            balanceQueues(firstHalf, secondHalf);
        }
    }

    return 0;
}
