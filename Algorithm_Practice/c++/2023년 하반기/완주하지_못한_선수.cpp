#include <string>
#include <vector>
#include <map>

using namespace std;

//map
//participant 돌면서 ++
//completion 돌면서 --
//마지막에 0보다 큰 이름이 완주하지 못한 선수
string solution(vector<string> participant, vector<string> completion) {
    map<string,int> nameAndCnt;
    string answer = "";
    
    for(int i=0; i<participant.size(); i++){
        nameAndCnt[participant[i]]++;
    }
    
    for(int i=0; i<completion.size(); i++){
        nameAndCnt[completion[i]]--;
    }
    
    for(auto m : nameAndCnt){
        if(m.second>0){
            answer = m.first;
            break;
        }
    }
    
    return answer;
}