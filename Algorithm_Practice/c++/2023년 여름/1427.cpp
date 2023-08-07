#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//숫자를 문자로 받아서 정렬
int main(){
    vector<char> num;
    string numStr;

    cin>>numStr; 

    for(int i=0; i<numStr.length(); i++){
        num.push_back(numStr[i]);
    }

    sort(num.begin(), num.end(), greater<>());

    for(int i=0; i<num.size(); i++){
        cout<<num[i];
    }
}