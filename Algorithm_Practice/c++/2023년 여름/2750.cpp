#include <iostream>
#include <set>

using namespace std;

int main(){
    int n, num;
    set<int> sortedNum; //중복없으므로 set이용

    cin>>n;

    for(int i=0; i<n; i++){
        cin>>num;
        sortedNum.insert(num);
    }

    for(auto m : sortedNum){
        cout<<m<<'\n';
    }
}