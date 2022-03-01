#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<string> solution(int T, vector<string> inputs){
    vector<string> answer;
		
		for(int i=0; i<T; i++){
			stack<char> st;
			bool flag=true; //stack이 비어있는데 ')'가 들어온 경우에 false로 바꾼다.
			for(int j=0; j<inputs[i].size(); j++){
				if(inputs[i][j]=='('){
					 st.push('(');
				}
				else if(!st.empty() && inputs[i][j]==')'){
					 st.pop();
				}
				else{
					flag=false;
					break;
				}
			}
			
            //연산이 다 끝났는데 stack이 비어있지 않거나 중간에 flag가 false여서 break된 경우를 거른다.
			if(!st.empty() || flag==false){ 
				answer.push_back("NO");
			}
			else{
				answer.push_back("YES");
			}
		}

    return answer;
}

void show(int n, vector<string>answer){
    int i;
    //test 출력
    for(i=0; i<n;i++)
       cout << answer[i] << '\n';
}
//test 메인
int main(){
    int T;
    cin >> T;
    vector<string> inputs(T);
    for (int i=0; i<T; i++) cin >> inputs[i];
    vector<string> answer = solution(T, inputs);
    show(T,answer);
    return 0;
}