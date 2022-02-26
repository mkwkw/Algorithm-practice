#include <iostream>
#include <set>

using namespace std;

int main(){
    set<int> s;
    int n, num;
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>num;
        s.insert(num);
    }

    for(auto iter : s){
        cout<<iter<<' ';
    }
}