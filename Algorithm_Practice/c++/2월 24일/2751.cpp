#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    vector<int> v;
    cin>>n;
    v.assign(n,0);

    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    sort(v.begin(), v.end());

    for(int i=0; i<n; i++){
        cout<<v[i]<<'\n';
    }
}