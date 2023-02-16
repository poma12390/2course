#include <iostream>
#include <set>
#include <stack>
#include <cstring>

using namespace std;

 

int main()
{   
    set<char> alphabet{'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    string str;
    cin >> str;
    char test[str.length()];
    strcpy(test, str.c_str());
    int n = sizeof(test) / sizeof(char)/2;
    int arr[n];
    for (size_t i = 0; i < n; i++) {
            arr[i]=0;
    }
    stack<char> s;
    int cages=0;
    int all_cage=0;
    int all_animals=0;
    bool prev_cage;
    int offset;
    int k;
    for (char i:test ){
        if(!s.empty()){
            if((char)tolower(s.top())==(char)tolower(i) && ((isupper(s.top()) && islower(i)) || (islower(s.top()) && isupper(i)))){
                if( islower(s.top())  && (isupper(i)) ){
                    k=0;
                }
                else{
                    k=1;
                    cout << "jopa" << endl;
                }
                if (prev_cage){ 
                    arr[cages-k+offset]=all_cage+1;
                }else{
                    arr[all_cage+cages-k]=all_cage+1;
                }
                s.pop();
                prev_cage=true;
                all_cage+=1;
                cages-=1;
            }else{
                prev_cage=false;
                s.push(i);
            }
        }else{
            //cout << "NEW BLOCK " << all_cage << endl;
            offset=all_cage;
            prev_cage=false;
            s.push(i);
        }    
        cages+=alphabet.count(i); 
        all_animals+=1-alphabet.count(i);   
    }
    if (cages!=0 || !s.empty()){
        cout<< "Impossible";
    }else{
        cout << "Possible" << endl;
        for (size_t i = 0; i < n; i++) {
        std::cout << arr[i] << ' ';
        }
    }
    return 0;
}