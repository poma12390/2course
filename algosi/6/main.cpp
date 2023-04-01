#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
    vector<string> vec;
    string s;
    while (cin>>s) vec.push_back(s);
    struct
    {
        bool operator()(string a, string b) const { return a+b>b+a; }
    }
    customLess;
    
    sort(begin(vec), end(vec), customLess);
    for (string s:vec) cout << s;
}