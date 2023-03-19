#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <sstream>


using namespace std;

bool isNumber(const std::string& s) {
    try {
        std::stoi(s);
    } catch (std::exception& e) {
        return false;
    }
    return true;
}

int main(){
    cout<<"Hello World";
    if(isNumber("-f34")){
        cout << " poma ";
    }else{
        cout << " kk";
    }
    return 0;
}