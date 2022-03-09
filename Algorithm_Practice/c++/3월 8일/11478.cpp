#include <iostream>
#include <set>

using namespace std;

int calculate(string str){
    set<string> s;
    string result = "";

    //ababc가 주어질 경우, a,ab,aba,abab,ababc/ b,ba,bab,babc/ .. 이렇게 부분문자열을 만든다.
    for(int i=0; i<str.size(); i++){
        for(int j=i; j<str.size(); j++){
            result += str[j];
            s.insert(result);
        }
        result = "";
    }

    return s.size();
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin>>str;

    int answer = calculate(str);
    cout<<answer;
}