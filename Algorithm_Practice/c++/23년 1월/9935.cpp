#include <iostream>
#include <stack>

using namespace std;

string explode(string original, string explosion){
    stack<char> st;
    stack<char> temp;
    string result="";

    int explosionLength = explosion.length();
    int originalLength = original.length();

    for(int i=0; i<originalLength; i++){
        //cout<<"originalLength: "<<originalLength<<" i: "<<i<<'\n';
        st.push(original[i]);
        if(original[i]==explosion[explosionLength-1] && st.size()>=explosionLength-1){
            
            //cout<<"i: "<<i<<" st.size(): "<<st.size()<<'\n';
            
            for(int j=0; j<explosionLength; j++){
                //cout<<"st.top: "<<st.top()<<" exp: "<<explosion[explosionLength-1-j]<<"\n";
                if(!st.empty()&&st.top()==explosion[explosionLength-1-j]){
                    //cout<<"st.top(): "<<st.top()<<'\n';
                    temp.push(st.top());
                    st.pop();
                }
                else{
                    //cout<<"temp.top(): "<<temp.top()<<'\n';
                    while(!temp.empty()){
                        st.push(temp.top());
                        temp.pop();
                    }
                    break;
                }
            }

            if(!temp.empty()){
                while(!temp.empty()){
                    temp.pop();
                }
            }

        }
    }

    if(st.empty()){
        result = "FRULA";
    }
    else{

        string tempResult="";
        while(!st.empty()){
            tempResult += st.top();
            st.pop();
        }

        for(int i=tempResult.length()-1; i>=0; i--){
            result += tempResult[i];
        }
    }

    return result;
}

int main(){
    string original, explosion, answer;
    cin>>original>>explosion;

    answer = explode(original, explosion);

    cout<<answer;
}

/**
 * 원래 문자열을 앞부분부터 하나씩 돌면서 폭발문자열과 일치하는지 검사
 * 일단 원래 문자열 하나씩 돌 때, st에 push
 * - 폭발문자열 뒷부분부터 원래 문자열(st.top)과 일치하는지 검사 - 일치하면 st.pop() 하고 temp 스택에 저장
 * -- 모두 일치하면 temp 스택 모두 pop - temp 스택 비우기
 * -- 중간에 일치하지 않으면 temp 스택에 있던 문자 모두 다시 st에 push
**/

// 스택 사용 이유 - 순서 고려해야함, 중간에 빠진 문자열을 계속 뒤에 것이랑 이어붙여야함, 남아있는 문자열이 있는지 없는지 검사해야함.
// 스택 사용 시 주의할 점 - empty, stack을 모두 비웠는지/비워야하는지