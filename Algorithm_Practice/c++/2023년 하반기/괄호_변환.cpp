#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>

using namespace std;

string result = "";
string v = "";
bool verifySyntax(string p){
    stack<char> st;
    
    for(int i=0; i<p.length(); i++){
        if(p[i]=='('){
            st.push('(');
        }
        else{
            if(st.empty()){
                return false;
            }
            st.pop();
        }
    }
    
    return true;
}

void makeRightSyntax(string p){
    //cout<<p<<'\n';
    int leftCnt = 0; // ( 개수
    int rightCnt = 0; // ) 개수
    int idx = 0;
    string u;
    
    if(p=="" || verifySyntax(p)){
        return;
    }
    
    for(int i=0; i<p.length(); i++){
        if(p[i]=='('){
            ++leftCnt;
        }
        else{
            ++rightCnt;
        }
        
        if(leftCnt==rightCnt){
            idx = i;
            break;
        }
    }
    
    u = p.substr(0,idx+1);
    v = p.substr(idx+1);
    //cout<<"u "<<u<<" v "<<v<<'\n';
    makeRightSyntax(v);
    
    if(verifySyntax(u)){
        //cout<<"final "<<u<<' '<<v<<'\n';
        result = u+result;
    }
    else{
        //cout<<"f ";
        result = "(" + v + ")";
        //cout<<result<<' ';
        u = u.substr(1,u.length()-2);
        reverse(u.begin(), u.end());
        result += u;
        //cout<<"final "<<result<<'\n';
    }
}

string solution(string p) {
    string answer = "";
    
    if(p==""){
        return "";
    }
    
    if(verifySyntax(p)){
        return p;
    }
    
    //입력이 올바르지 않은 괄호 문자열일 때
    makeRightSyntax(p);
    answer = result;
    
    return answer;
}