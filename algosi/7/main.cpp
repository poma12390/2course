#include <iostream>
#include <algorithm>
using namespace std;

int32_t weights[26];

bool compare(const char &x1, const char &x2){
    int32_t x1_weight = weights[x1 - 'a'];
    int32_t x2_weight = weights[x2 - 'a'];
    if (x1_weight == x2_weight) {
        return x1 > x2;
    } else {
        return x1_weight > x2_weight;
    }
}

int main() {
    string s;
    cin >> s;
    for (int i = 0; i < 26; i++) {
        cin >> weights[i];
    }

    string result = "";
    string heavy_letters = "";
    sort(s.begin(), s.end(), compare);

    for (int i = 0; i < s.size() - 1; i++) {
        char current_char = s[i];
        char next_char = s[i + 1];
        bool is_same = current_char == next_char;

        bool heavy_letters_is_empty = heavy_letters.empty();
        bool heavy_letters_not_same = !heavy_letters_is_empty && heavy_letters[heavy_letters.size() - 1] != current_char;

        if (is_same && (heavy_letters_not_same || heavy_letters_is_empty)) {
            heavy_letters.push_back(current_char);
            i++;
        } else {
            result.push_back(current_char);
        }
    }

    int result_size = result.size();
    int heavy_letters_size = heavy_letters.size();
    int remaining_letters = s.size() - result_size - 2 * heavy_letters_size;

    if (remaining_letters > 0) {
        result.push_back(s[s.size() - 1]);
    }

    cout << heavy_letters;
    cout << result;

    for(int i = heavy_letters_size - 1; i >= 0; i--) {
        cout << heavy_letters[i];
    }

    return 0;
}
