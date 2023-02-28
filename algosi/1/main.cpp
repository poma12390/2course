#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> vector_in(vector<int> vector, int n){
    for (int i=0; i<n; i++){
        int a;
        cin >> a;
        vector.push_back(a);
        
    }
    return vector;
}


int main()
{

    int end =1;
    int start =0;
    int end_max =1;
    int start_max =0;

    int n;
    
    vector<int> vector1;
    cin>>n;
    vector1=vector_in(vector1, n);
    if (n < 3) {
        cout << 1 << " " << n;
        return 0;
    }

    for (int i=2; i<n; i++){
        end=i;
        if (vector1[i]==vector1[i-1] && vector1[i]==vector1[i-2]){
            if (end-start-1>end_max-start_max){
                end_max=end-1;
                start_max=start;

            }
            start=i-1;
        }
        

    }
    if (end-start>end_max-start_max){
                end_max=end;
                start_max=start;
            }
    // cout << start << " " << end << " max "  << start_max << " " << end_max << endl;
    cout << start_max+1 << " " << end_max+1; 
    
    return 0;
}