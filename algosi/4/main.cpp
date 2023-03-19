#include <iostream>
<<<<<<< HEAD
#include <vector>

using namespace std;

int day(int a, int b, int c, int d){
    int n;
    n=min(a*b-c, d);
    if (n<=0){
        n=0;
    }
    return n;

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
    string s="";
    getline(cin, s);
    //cout<<s << endl;
    vector <string> v= split(s, " ");
    int a = stoi(v[0]); 
    int b = stoi(v[1]);
    int c = stoi(v[2]);
    int d = stoi(v[3]);
    long k = stoi(v[4]);
    int now=0;
    for(long i=0; i<k; i++){
        now=day(a,b,c,d);
        
        if(now==a || now==d || now==0){
            cout << now;
=======

int main() {
    int a, b, c, d, now;
    long k;
    std::cin >> a >> b >> c >> d >> k;
    for(long i=0; i<k; i++){
        now=(std::min(a*b-c, d)>0)? std::min(a*b-c, d) : 0;
        if(now==a || now==d || now==0){
            std::cout << now;
>>>>>>> 0f98e603cac9617a58edd1884399f3a35cc013ce
            return 0;
        }else{
            a=now;
        }
    }
<<<<<<< HEAD
    cout<<a;
=======
    std::cout<<a;
>>>>>>> 0f98e603cac9617a58edd1884399f3a35cc013ce
    return 0;
}