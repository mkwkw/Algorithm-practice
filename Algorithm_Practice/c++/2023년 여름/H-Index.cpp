#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int minCnt, maxCnt;
    
    sort(citations.begin(), citations.end());
    
    minCnt = 0; //0부터 시작해야함. [1000]인 경우, 답은 1이다.
    maxCnt = citations[citations.size()-1];
    
    for(int i=minCnt; i<=maxCnt; i++){
        int cnt = 0;
        for(int j=0; j<citations.size(); j++){
            if(i<=citations[j]){
                cnt++;
            }
        }
        
        if(cnt>=i){
            answer = i;
        }
        else{
            break;
        }
    }
    
    return answer;
}