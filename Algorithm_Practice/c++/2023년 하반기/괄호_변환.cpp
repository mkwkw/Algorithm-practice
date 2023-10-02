#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>

using namespace std;

//재귀, 스택
//1. 스택으로 올바른 문자열인지 확인
//2-1. u가 올바른 문자열이라면 u+makeRightSyntax(v)
//2-2. u가 올바르지 않은 문자열이라면 (makeRightSyntax(v))+앞뒤 떼고 괄호 반대로 바꾼 u
string result = "";
string vPrime = "";
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

//string으로 리턴하도록!
string makeRightSyntax(string p){
    //cout<<p<<'\n';
    int leftCnt = 0; // ( 개수
    int rightCnt = 0; // ) 개수
    int idx = 0;
    string u,v;
    
    if(p=="" || verifySyntax(p)){
        return p;
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
    vPrime = makeRightSyntax(v); //재귀를 거친 v 만들기
    
    //cout<<"v "<<vPrime<<'\n';
    //u가 올바른 괄호 문자열일 때
    if(verifySyntax(u)){
        //cout<<"final "<<u<<' '<<result<<'\n';
        result = u+vPrime;
    }
    else{//u가 올바른 괄호 문자열이 아닐 때
        //cout<<"f ";
        //cout<<"ffinal "<<u<<' '<<vPrime<<' '<<result<<'\n';
        result = "(" + vPrime + ")";
        //cout<<result<<' ';
        u = u.substr(1,u.length()-2);
        for(int i=0; i<u.length(); i++){
            if(u[i]==')'){
                u[i] = '(';
            }
            else{
                u[i] = ')';
            }
        }
        result += u;
        //cout<<"final "<<result<<'\n';
    }
    
    return result;
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