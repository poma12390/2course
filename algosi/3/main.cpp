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

<<<<<<< HEAD
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
=======
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
>>>>>>> ff21196161afd81706d9d4f6c9070f3a6de2d8bd
    }
    //cout << "}" << endl;
}

<<<<<<< HEAD
void var_to_var(unordered_map <string, vector<int>> &m, string &var_name, string &var_name1, unordered_map <string, vector<int>> :: iterator &it, vector <vector<string>> &history){
=======
map <string, vector<int>> var_to_var(map <string, vector<int>> m, string var_name, string var_name1, map <string, vector<int>> :: iterator it){
>>>>>>> ff21196161afd81706d9d4f6c9070f3a6de2d8bd
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
<<<<<<< HEAD
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
=======
    cout << var_name << "="<<m.find(var_name1)->second.back() <<endl;
    m.find(var_name)->second.back()=m.find(var_name1)->second.back();
    return m;
}

map <string, vector<int>> int_to_var(map <string, vector<int>> m, string var_name, int n, map <string, vector<int>> :: iterator it){
>>>>>>> ff21196161afd81706d9d4f6c9070f3a6de2d8bd
    it = m.find(var_name);
    if(it==m.end()){
        m.insert({var_name, new_vector(0)});
        //cout << "New var(int_to_var) "<< var_name << endl;
    }
    //cout << var_name<<"=(int)"<<n<<endl;
<<<<<<< HEAD
    history.back().push_back(var_name);
    //cout<< var_name  << " push" << endl;
    m.find(var_name)->second.push_back(n);
=======
    m.find(var_name)->second.back()=n;
    return m;
>>>>>>> ff21196161afd81706d9d4f6c9070f3a6de2d8bd
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
<<<<<<< HEAD
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
=======
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
>>>>>>> ff21196161afd81706d9d4f6c9070f3a6de2d8bd
            }
        }
        
}
<<<<<<< HEAD
}
=======
}
>>>>>>> ff21196161afd81706d9d4f6c9070f3a6de2d8bd
