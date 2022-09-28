#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int k, maxWeight=0;
    vector<int> ropes;

    cin>>k;
    ropes.assign(k,0);

    for(int i=0; i<k; i++){
        cin>>ropes[i];
    }

    sort(ropes.begin(), ropes.end());

    for(int i=0; i<k; i++){
        int weight = ropes[i]*(k-i);

        if(maxWeight<weight){
            maxWeight = weight;
        }
    }

    cout<<maxWeight;
}