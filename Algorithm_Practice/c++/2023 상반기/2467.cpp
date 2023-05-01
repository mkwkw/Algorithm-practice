#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    long long ansSum = 2*1e9+1, ansLeft = 0, ansRight = 0;
    vector<long long> liquid;

    cin>>n;

    liquid.assign(n, 0);

    for(int i=0; i<n; i++){
        cin>>liquid[i];
    }

    int left = 0;
    int right = n-1;
    while(left<right){

        long long liquidSum = liquid[left]+liquid[right];
        
        if(abs(liquidSum)<ansSum){
            ansLeft = left;
            ansRight = right;
            ansSum = abs(liquidSum);
        }
        
        if(liquidSum==0){
            break;
        }
        else if(liquidSum<0){
            left++;
        }
        else{
            right--;
        }
    }

    cout<<liquid[ansLeft]<<' '<<liquid[ansRight];
}