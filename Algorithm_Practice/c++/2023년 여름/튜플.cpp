#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

//map으로 숫자와 숫자 출현 빈도 저장
//숫자 출현 빈도가 많을수록 answer 벡터에서 앞에 위치

vector<int> solution(string s) {
    vector<int> answer;
    vector<pair<int,int>> cntAndNum;
    map<int, int> numAndCnt;
    
    //숫자 찾기(숫자 이어붙이기)
    bool flag = false;
    string str = "";
    for(int i=0; i<s.length(); i++){
        if(s[i]=='{'){
            flag = true;
        }
        
        if(s[i]=='}'){
            flag = false;
            if(str.length()>0){
                int n = stoi(str);
                numAndCnt[n]++;
                str = "";
            }
        }
        
        if(s[i]==',' && str.length()>0){
            int n = stoi(str);
            numAndCnt[n]++;
            str = "";
        }
        
        if(flag && s[i]>='0' && s[i]<='9'){
            str += s[i];
        }
    }
    
    for(auto p : numAndCnt){
        cntAndNum.push_back({p.second, p.first});
    }
    
    sort(cntAndNum.begin(), cntAndNum.end(), greater<>());
    
    for(int i=0; i<cntAndNum.size(); i++){
        answer.push_back(cntAndNum[i].second);
    }
    
    return answer;
}