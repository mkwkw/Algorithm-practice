#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<int> num;
    int n, answer = 0;

    cin>>n;

    num.assign(n, 0);

    for(int i=0; i<n; i++){
        cin>>num[i];
    }

    sort(num.begin(), num.end());

    answer = num[0]*num[n-1];

    cout<<answer;
}