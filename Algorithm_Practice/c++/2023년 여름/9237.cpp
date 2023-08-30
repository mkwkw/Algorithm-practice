#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, maxDay = 0;
    vector<int> trees;

    cin>>n;

    trees.assign(n, 0);

    for(int i=0; i<n; i++){
        cin>>trees[i];
    }

    sort(trees.begin(), trees.end(), greater<>());

    for(int i=0; i<n; i++){
        maxDay = max(i+2+trees[i]-1, maxDay);
    }

    cout<<maxDay+1;
}