#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(){
    vector<pair<int,int>> pos;
    stack<int> st;
    int n, height = 0, answer = 0, startH = 0;
    
    cin>>n;

    pos.assign(n, {0,0});
    for(int i=0; i<n; i++){
        cin>>pos[i].first>>pos[i].second;
    }

    //�ִ� �ͺ��� ���� ���� �߿�
    //top���� ������ �ֱ�
    //top���� ������ ���� + answer ����
    //���� empty����

    for(int i=0; i<n; i++){
        if(st.empty() && pos[i].second>0){
            //cout<<"push: "<<pos[i].second<<'\n';
            st.push(pos[i].second);
        }
        else if(!st.empty()){
            if(st.top()<pos[i].second){
                //cout<<"push: "<<pos[i].second<<'\n';
                st.push(pos[i].second);
            }
            else if(st.top()>pos[i].second){
                while(!st.empty() && st.top()>pos[i].second ){
                    //cout<<"pop: "<<st.top()<<'\n';
                    st.pop();
                    answer++;
                }

                if(!st.empty() && st.top()<pos[i].second){
                    st.push(pos[i].second);
                }
                else if(st.empty() && pos[i].second>0){
                    st.push(pos[i].second);
                }
            }
        }

        //cout<<"answer: "<<answer<<'\n';

    }

    if(!st.empty()){
        answer += st.size();
    }

    cout<<answer;

}