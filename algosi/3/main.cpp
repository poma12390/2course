#include <iostream>
#include <unordered_map>
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

void push_all(vector <vector<string>> &history){
    //cout << "{" << endl;
    history.push_back(vector<string>{});
}

void pop_all(unordered_map <string, vector<int>> &m, vector <vector<string>> &history){
    vector<string> v = history.back();
    history.pop_back();
    for (string s: v){
        //cout << " pop " << s;
        m[s].pop_back();
    }
    //cout << "}" << endl;
}

void var_to_var(unordered_map <string, vector<int>> &m, string &var_name, string &var_name1, unordered_map <string, vector<int>> :: iterator &it, vector <vector<string>> &history){
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
    //cout<< var_name << " and " << var_name1 << " push" << endl;
    history.back().push_back(var_name);

    // for(auto a: m){
    //    for(auto i: a.second){
    //      cout << a.first << " = " << i;
    //    }
    //    cout << endl;
    // }
    cout<<m.find(var_name1)->second.back()  << endl;
    m.find(var_name)->second.push_back(m.find(var_name1)->second.back());

    
}

void int_to_var(unordered_map <string, vector<int>> &m, string var_name, int n, unordered_map <string, vector<int>> :: iterator &it, vector <vector<string>> &history){
    it = m.find(var_name);
    if(it==m.end()){
        m.insert({var_name, new_vector(0)});
        //cout << "New var(int_to_var) "<< var_name << endl;
    }
    //cout << var_name<<"=(int)"<<n<<endl;
    history.back().push_back(var_name);
    //cout<< var_name  << " push" << endl;
    m.find(var_name)->second.push_back(n);
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
    unordered_map <string, vector<int>> m;
    unordered_map <string, vector<int>> :: iterator it;
    vector<string> v;
    vector <vector<string>> history;
    history.push_back(vector<string>());
    while (cin>>s){
        if (s=="{"){
            push_all(history);
        }else if (s=="}")
        {
            pop_all(m, history);
        }
        else{      
            v=split(s, "=");
            if(isNumber(v[1])){
                int_to_var(m, v[0], stoi(v[1]), it, history);
            }else{
                var_to_var(m, v[0], v[1], it, history);
            }
        }
        
}
}