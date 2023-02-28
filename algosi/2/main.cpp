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
    stack<char> zoo;
    stack<int> animals_num;
    stack<int> cages_num;
    int cage_num=0;
    int animal_num=1;
    for (char i: str){
        if (tolower(i)==i){   
            //cout << "animal " << animal_num<< endl;
            animals_num.push(animal_num);
            animal_num++;
        }else{
            cages_num.push(cage_num);
           // cout << "cage " << cage_num<< endl;
            cage_num++;
        }

        if(!zoo.empty()){
            if(  (islower(i)&& isupper(zoo.top()) && tolower(zoo.top())==i) || (isupper(i) && islower(zoo.top()) && toupper(zoo.top())==i)){
                arr[cages_num.top()]=animals_num.top();
               // cout << cages_num.top() << " index " << animals_num.top() << " number" << endl;
                zoo.pop();
                animals_num.pop();
                cages_num.pop();
            }else zoo.push(i);
        }else zoo.push(i);
        
    }

    if (!zoo.empty()){
            cout<< "Impossible";
        }else{
            cout << "Possible" << endl;
            for (size_t i = 0; i < n; i++) {
            std::cout << arr[i] << ' ';
            }
        }
    return 0;
}