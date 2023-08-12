#include <string>
#include <vector>
#include <string>
#include <stack>
#include <cmath>
#include <iostream>
#include <sstream>

using namespace std;

//n을 k진수로 바꾸기
//소수 판별
//sstream 이용해서 parsing하기

stack<int> st;
string kNumStr = "";
int answer = 0;

//n을 k진수로 바꾸기
void nToKNum(int n, int k){
    
    if(n>=k){
        st.push(n%k);
        nToKNum(n/k, k);
    }
    else{
        st.push(n);
        return;
    }
}

//'0' 기준으로 나누고 소수인지 판별
int solution(int n, int k) {
    long long answer = 0, kNum = 0, startIdx = 0;
    string numStr = "";
    vector<long long> partNums;
    
    nToKNum(n,k);
    
    //k진수
    while(!st.empty()){
        numStr += to_string(st.top());
        st.pop();        
    }
    
    string token;
    stringstream ss(numStr);
    while(getline(ss, token, '0')){
        if(token!=""){
            long long partNum = stol(token);
            partNums.push_back(partNum);
        }
    }
    
    for(int i=0; i<partNums.size(); i++){
        if(partNums[i]==0 || partNums[i]==1){
            continue;
        } 
        
        bool flag = true;
        for(int j=2; j<=sqrt(partNums[i]); j++){
            if(partNums[i]%j==0){
                flag = false;
                break;
            }
        }
        
        if(flag){
            answer++;
        }
    }
    
    return answer;
}

int main(){
    
    cout<<solution(110011, 10);
}