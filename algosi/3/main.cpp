#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> new_vector(int a){
    vector<int> vec={a};
    return vec;
}
bool isNumber(string& str)
{
    for (char const &c : str) {
        if (isdigit(c) == 0)
          return false;
    }
    return true;
}

map <string, vector<int>> push_all(map <string, vector<int>> m){
    for (auto &i : m){
        i.second.push_back(i.second.back());
    }
    return m;
}

map <string, vector<int>> pop_all(map <string, vector<int>> m){
    for (auto &i : m){
        i.second.pop_back();
    }
    return m;
}

int main() {
    freopen("output.txt","w",stdout);
    freopen("input.txt","r",stdin);
    string s;
    map <string, vector<int>> m;
    map <string, vector<int>> :: iterator it;
    // m.insert({"Poma", new_vector(147)});
    // it = m.find("Poma");
    // cout << "before " << it->second.size() << endl;
    // m=push_all(m);
    // it = m.find("Poma");
    // cout << "middle " << it->second.size() << endl;
    // m=pop_all(m);
    // it = m.find("Poma");
    // cout << "after " << it->second.size() << endl;

    while (cin>>s)
    { 
        if(isNumber(s)){
            cout<<"yes" << endl;
        }
        else{
            cout << "no" << endl;
            }
    }
    
    
    // if(it!=m.end()){
    //     cout << it->second[0];
    // }
    // else{
    //     cout<<12;
    // }

}