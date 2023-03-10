#include <iostream>

int main() {
    int a, b, c, d, now;
    long k;
    std::cin >> a >> b >> c >> d >> k;
    for(long i=0; i<k; i++){
        now=(std::min(a*b-c, d)>0)? std::min(a*b-c, d) : 0;
        if(now==a || now==d || now==0){
            std::cout << now;
            return 0;
        }else{
            a=now;
        }
    }
    std::cout<<a;
    return 0;
}