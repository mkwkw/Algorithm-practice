#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
#include <iostream>

using namespace std;

//스택, 그리디
//stack의 top이 number[i] 보다 작은 동안 pop
string solution(string number, int k) {
    string answer = "";
    stack<char> st;
    int remainedIdx = 0;
    
    for(int i=0; i<number.length(); i++){    
        if(st.empty()){
            st.push(number[i]);
        }
        else{
            while(!st.empty() && k>0){
                if(st.top()<number[i]){
                    //cout<<st.top()<<'\n';
                    st.pop();
                    k--;
                    //cout<<"k "<<k<<'\n';
                }
                else{
                    break;
                }
            }
            st.push(number[i]);
        }
        
        if(k==0){
            remainedIdx = i+1;
            //cout<<"idx "<<remainedIdx<<'\n';
            break;
        }
    }
    
    while(!st.empty()){
        answer += st.top();
        st.pop();
    }
    
    reverse(answer.begin(), answer.end());
    
    if(answer.length()==number.length()){
        answer = number.substr(0, number.length()-1);
    }
    else{
        for(int i=remainedIdx; i<number.length(); i++){
            answer += number[i];
        }
    }
    
    return answer;
}