#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <sstream>


using namespace std;

vector<int> new_vector(int a){
    vector<int> vec={a};
    return vec;
}
bool isNumber(const std::string& s) {
    try {
        stoi(s);
    } catch (exception& e) {
        return false;
    }
    return true;
}

map <string, vector<int>> push_all(map <string, vector<int>> m){
    //cout << "pushall" << endl;
    for (auto &i : m){
        i.second.push_back(i.second.back());
    }
    return m;
}

map <string, vector<int>> pop_all(map <string, vector<int>> m){
    //cout << "popall" << endl;
    for (auto &i : m){
        i.second.pop_back();
    }
    return m;
}

map <string, vector<int>> var_to_var(map <string, vector<int>> m, string var_name, string var_name1, map <string, vector<int>> :: iterator it){
    it = m.find(var_name);
    if(it!=m.end()){
        //cout<< var_name << " already= " << it->second[it->second.size()-1] << endl;
    }
    else{
        //cout << "New var "<< var_name << endl;
        m.insert({var_name, new_vector(0)});
    }
    it = m.find(var_name1);
    if(it!=m.end()){
       //cout<< var_name1 << " already= " << it->second[it->second.size()-1] << endl;
    }
    else{
        //cout << "New var "<< var_name1 << endl;
        m.insert({var_name1, new_vector(0)});
    }
    cout << var_name << "="<<m.find(var_name1)->second.back() <<endl;
    m.find(var_name)->second.back()=m.find(var_name1)->second.back();
    return m;
}

map <string, vector<int>> int_to_var(map <string, vector<int>> m, string var_name, int n, map <string, vector<int>> :: iterator it){
    it = m.find(var_name);
    if(it==m.end()){
        m.insert({var_name, new_vector(0)});
        //cout << "New var(int_to_var) "<< var_name << endl;
    }
    //cout << var_name<<"=(int)"<<n<<endl;
    m.find(var_name)->second.back()=n;
    return m;
}

vector<string> split(string s, string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}


int main() {
    freopen("output.txt","w",stdout);
    freopen("input.txt","r",stdin);
    string s;
    map <string, vector<int>> m;
    map <string, vector<int>> :: iterator it;
    // m.insert({"Poma", new_vector(1147)});
    // m=int_to_var(m, "Poma", 1669, it);
    // m=var_to_var(m, "seledka", "Poma", it);
    // cout << m.find("seledka")->second.back();
        vector<string> v;
    while (cin>>s){
        
        if (s=="{"){
            m=push_all(m);
        }else if (s=="}")
        {
            m=pop_all(m);
        }
        else{
            
            v=split(s, "=");
            if(isNumber(v[1])){
                m=int_to_var(m, v[0], stoi(v[1]), it);
            }else{
                cout << s << " string " << endl;
                m=var_to_var(m, v[0], v[1], it);
            }
        }
        
}
}
