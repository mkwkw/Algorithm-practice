#include <iostream>
#include <stack>

using namespace std;

int main(){
    string str, answer="";
    bool flag = false; //태그 구분자
    stack<char> st; //단어 넣을 스택

    getline(cin, str); //공백 포함해서 입력 받기

    for(int i=0; i<str.length(); i++){

        if(str[i]=='<'){
            flag = true;

            //ex. 123<tag>일 때
            while(!st.empty()){
                answer += st.top();
                st.pop();
            }
        }

        else if(str[i]=='>'){
            flag = false;
        }

        //태그 부분일 때는 순서대로 출력
        if(flag || str[i]=='>'){
            answer += str[i];
        }
        else{ //단어 부분인 경우 (태그가 아닐 때) - 공백 주의
            
            if(str[i]!=' '){
                st.push(str[i]);
            }
            else{
                while(!st.empty()){
                    answer += st.top();
                    st.pop();
                }
                answer += ' '; // 공백은 스택에 push 하면 안 됨
            }
        }

    }

    //마지막에 태그 없이 끝나는 경우 처리
    while(!st.empty()){
        answer += st.top();
        st.pop();
    }

    cout<<answer;
}