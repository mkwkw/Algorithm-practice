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
 * ���� ���ڿ��� �պκк��� �ϳ��� ���鼭 ���߹��ڿ��� ��ġ�ϴ��� �˻�
 * �ϴ� ���� ���ڿ� �ϳ��� �� ��, st�� push
 * - ���߹��ڿ� �޺κк��� ���� ���ڿ�(st.top)�� ��ġ�ϴ��� �˻� - ��ġ�ϸ� st.pop() �ϰ� temp ���ÿ� ����
 * -- ��� ��ġ�ϸ� temp ���� ��� pop - temp ���� ����
 * -- �߰��� ��ġ���� ������ temp ���ÿ� �ִ� ���� ��� �ٽ� st�� push
**/

// ���� ��� ���� - ���� ����ؾ���, �߰��� ���� ���ڿ��� ��� �ڿ� ���̶� �̾�ٿ�����, �����ִ� ���ڿ��� �ִ��� ������ �˻��ؾ���.
// ���� ��� �� ������ �� - empty, stack�� ��� �������/������ϴ���