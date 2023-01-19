#include <iostream>
#include <stack>

using namespace std;

int main(){
    stack<char> st;
    string sticks;
    int answer = 0, cnt = 0;
    cin>>sticks;

    for(int i=0; i<sticks.size(); i++){
        if(sticks[i]=='('){
            st.push('(');
        }
        else {
            
            st.pop();
            
            if(sticks[i-1]=='('){ //레이저인 경우 - 이전 것 (, 지금 것 )
                answer += st.size();
            }
            else{ //쇠막대기의 끝인 경우 - 이전 것 ), 지금 것 ) - 굳이 ')' 연속 개수 따질 필요 없음 - for문으로 하나씩 읽어나가기 때문에 answer++ 하면 됨.
                answer++; 
            }
        }
    }

    cout<<answer;

}