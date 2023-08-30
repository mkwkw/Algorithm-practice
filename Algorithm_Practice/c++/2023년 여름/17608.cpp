#include <iostream>
#include <stack>

using namespace std;

//스택
//top과 h 비교
int main(){
    int n, h;
    stack<int> st;

    cin>>n;

    for(int i=0; i<n; i++){
        cin>>h;

        if(st.empty() || (!st.empty()&&st.top()>h)){
            st.push(h);
        }
        else{
            while(!st.empty()&&st.top()<=h){
                st.pop();
            }
            st.push(h);
        }
        
    }

    cout<<st.size();
}