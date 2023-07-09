#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

//스택, 큐 같이 활용
//맨 앞 문자를 맨 뒤에 넣으면서 회전 - 큐
//올바른 괄호 판단 - 스택 - 올바르지 않은 경우(닫힌 괄호로 시작하는 경우, 올바른 괄호 쌍 다 뺐는데도 스택에 원소가 남아있는 경우)
int solution(string s) {
    queue<char> q;
    int answer = 0;
    
    for(int i=0; i<s.length(); i++){
        q.push(s[i]);
    }
    
    for(int i=0; i<s.length(); i++){
        bool flag = true;
        //한 칸 회전
        q.push(q.front());
        q.pop();
        
        stack<char> st;
        queue<char> temp;
        temp = q;
        
        while(!temp.empty()){
            
            if(st.empty() 
                && (temp.front()==']' || temp.front()=='}' || temp.front()==')')){
                flag = false;
                break;
            }
            
            if(temp.front()=='[' || temp.front()=='{' || temp.front()=='('){
                st.push(temp.front());
            }
            
            if((st.top()=='[' && temp.front()==']') 
               || (st.top()=='{' && temp.front()=='}') 
               || (st.top()=='(' && temp.front()==')')){
                st.pop();
            }
            temp.pop();
        }
        
        if(!st.empty()){
            flag = false;
        }
        
        if(flag){
            answer++;
        }
    }
    
    return answer;
}