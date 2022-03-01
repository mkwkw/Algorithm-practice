#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<string> solution(int T, vector<string> inputs){
    vector<string> answer;
		
		for(int i=0; i<T; i++){
			stack<char> st;
			bool flag=true; //stack�� ����ִµ� ')'�� ���� ��쿡 false�� �ٲ۴�.
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
			
            //������ �� �����µ� stack�� ������� �ʰų� �߰��� flag�� false���� break�� ��츦 �Ÿ���.
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
    //test ���
    for(i=0; i<n;i++)
       cout << answer[i] << '\n';
}
//test ����
int main(){
    int T;
    cin >> T;
    vector<string> inputs(T);
    for (int i=0; i<T; i++) cin >> inputs[i];
    vector<string> answer = solution(T, inputs);
    show(T,answer);
    return 0;
}