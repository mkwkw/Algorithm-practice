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
            
            if(sticks[i-1]=='('){ //�������� ��� - ���� �� (, ���� �� )
                answer += st.size();
            }
            else{ //�踷����� ���� ��� - ���� �� ), ���� �� ) - ���� ')' ���� ���� ���� �ʿ� ���� - for������ �ϳ��� �о���� ������ answer++ �ϸ� ��.
                answer++; 
            }
        }
    }

    cout<<answer;

}