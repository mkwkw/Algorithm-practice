#include <iostream>

using namespace std;

int main(){
    int n, answer=0;
    string num;

    cin>>n>>num;

    for(int i=0; i<n; i++){
        answer += num[i]-'0';
    }

    cout<<answer;
}