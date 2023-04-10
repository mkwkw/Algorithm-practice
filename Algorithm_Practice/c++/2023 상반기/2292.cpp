#include <iostream>

using namespace std;

int main(){
    int n, temp = 1, i=0;
    cin>>n;

    for(i=0; i<1000000000; i++){
        temp += 6*i;
        if(temp>=n){
            break;
        }
    }

    cout<<i+1;
}