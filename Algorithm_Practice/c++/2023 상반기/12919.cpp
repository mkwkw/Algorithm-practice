#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string s, t;
bool answer = false;


//1. s->t : s에다 매번 A 붙여보고,  B 붙여봐야함 -> 시간 초과
//2. t->s : t의 맨 앞 문자가 B인 경우, 맨 끝 문자가 A인 경우 나누어서 처리할 수 있음!
void recur(string str){
    //cout<<str<<'\n';

    if(answer){
        return;
    }
    
    if(str.length() == s.length()){
        if(str == s){
            answer = true;
        }
        else{
            answer = false;
        }
        return;
    }

    if(str[str.length()-1] == 'A'){
        string tmp = str;
        tmp.erase(tmp.length()-1, 1);
        recur(tmp);
    }

    //cout<<"st: "<<str<<'\n';
    if(str[0]=='B'){
        string tmp = str;
        tmp.erase(0, 1);
        
        reverse(tmp.begin(), tmp.end());
        recur(tmp);
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>s>>t;

    recur(t);
   
    cout<<answer;
}