#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n, answer = 0;
    
    cin>>n;

    for(int i=0; i<n; i++){
        int num;
        bool flag = true;
        cin>>num;

        for(int j=2; j<=sqrt(num); j++){
            if(num%j==0){
                flag = false;
                break;
            }
        }

        if(num!=1 && flag){
            answer++;
        }
    }

    cout<<answer;
}