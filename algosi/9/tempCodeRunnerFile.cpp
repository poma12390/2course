#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

int main() {
    int N, K, P;
    cin >> N >> K >> P;

    vector<int> cars(P);
    for (int i = 0; i < P; i++) {
        cin >> cars[i];
    }

    unordered_map<int, int> next_car;
    vector<int> next_car_index(P, -1);

    for (int i = P - 1; i >= 0; i--) {
        int car = cars[i];
        if (next_car.find(car) != next_car.end()) {
            next_car_index[i] = next_car[car];
        }
        next_car[car] = i;
    }

    int operations = 0;
    map<int, int> cars_on_floor;

    for (int i = 0; i < P; i++) {
        int car = cars[i];
        auto it = cars_on_floor.find(car);

        if (it == cars_on_floor.end()) {
            if (cars_on_floor.size() < K) {
                cars_on_floor.insert({car, next_car_index[i]});
                operations++;
            } else {
                auto car_to_remove = prev(cars_on_floor.end());
                cars_on_floor.erase(car_to_remove);
                cars_on_floor.insert({car, next_car_index[i]});
                operations++;
            }
        } else {
            it->second = next_car_index[i];
        }
    }

    cout << operations << endl;

    return 0;
}
