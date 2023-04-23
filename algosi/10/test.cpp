#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main(){
    int k;
    std::deque<int> deque1;    
    deque1.push_back(1);
    deque1.push_back(2);
    deque1.push_back(3);
    deque1.pop_front();
    k = deque1.front();
    cout << k;
}