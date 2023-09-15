#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

//stack
vector<int> solution(vector<int> arr) 
{
    stack<int> st;
    vector<int> answer;

    for(int i=0; i<arr.size(); i++){
        if(st.empty()){
            st.push(arr[i]);
        }
        else{
            if(st.top()==arr[i]){
                continue;
            }
            else{
                st.push(arr[i]);
            }
        }
    }
    
    while(!st.empty()){
        answer.push_back(st.top());
        st.pop();
    }
    
    reverse(answer.begin(), answer.end());

    return answer;
}