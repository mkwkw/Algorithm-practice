#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
     vector<int> answer;
    stack<int> st; //스택에 시간 저장
    int n = prices.size();
    answer.assign(n,0);
    
    st.push(0);
    
    for(int i=1; i<n; i++){
        
        while(!st.empty()&&prices[st.top()]>prices[i]){
            answer[st.top()]=i-st.top();
            st.pop();
        }
        
        st.push(i);   
        
    }
    while(!st.empty()){
        answer[st.top()]=n-1-st.top();
        st.pop();
    }
    
    return answer;
}

/*순서를 지켜야되고 시간이 누적되어야하므로 스택을 쓰자.
1. 스택을 넣고 빼는 기준을 정해서 코드를 짜자. if문으로 함.
그리고 prices끝까지 넣고 남은 스택의 것들을 빼면서 answer를 계산하자.
answer = n-1-st.top()이다.
-> 틀림
2. 뭐가 문제일까
- 만약에 st.top()의 가격이 i의 가격보다 큰 것이 여러 개이면 if문만으로는 안 된다.
while문으로 바꿔서 하자.
-> 정답
*/