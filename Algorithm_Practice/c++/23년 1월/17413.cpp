#include <iostream>
#include <stack>

using namespace std;

int main(){
    string str, answer="";
    bool flag = false; //�±� ������
    stack<char> st; //�ܾ� ���� ����

    getline(cin, str); //���� �����ؼ� �Է� �ޱ�

    for(int i=0; i<str.length(); i++){

        if(str[i]=='<'){
            flag = true;

            //ex. 123<tag>�� ��
            while(!st.empty()){
                answer += st.top();
                st.pop();
            }
        }

        else if(str[i]=='>'){
            flag = false;
        }

        //�±� �κ��� ���� ������� ���
        if(flag || str[i]=='>'){
            answer += str[i];
        }
        else{ //�ܾ� �κ��� ��� (�±װ� �ƴ� ��) - ���� ����
            
            if(str[i]!=' '){
                st.push(str[i]);
            }
            else{
                while(!st.empty()){
                    answer += st.top();
                    st.pop();
                }
                answer += ' '; // ������ ���ÿ� push �ϸ� �� ��
            }
        }

    }

    //�������� �±� ���� ������ ��� ó��
    while(!st.empty()){
        answer += st.top();
        st.pop();
    }

    cout<<answer;
}