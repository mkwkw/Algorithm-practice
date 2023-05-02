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

    //넣는 것보다 빼는 것이 중요
    //top보다 높으면 넣기
    //top보다 작으면 빼기 + answer 증가
    //스택 empty주의

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