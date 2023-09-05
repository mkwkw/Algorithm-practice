#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

//next_permutation, set, 문자열
bool verify(string userId, string bannedId){ //userId가 bannedId 후보가 될 수 있는가
    bool flag = true;
    if(userId.length()==bannedId.length()){
        for(int i=0; i<userId.length(); i++){
            if(bannedId[i]!='*' && bannedId[i]!=userId[i]){
                flag = false;
                break;
            }
        }
        return flag;
    }
    return false;
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    set<string> idSet;
    //user_id로 모든 순열 만들기 (user_id.size() P banned_id.size())
    sort(user_id.begin(), user_id.end());
    
    do{
        bool flag = true;
        string allId = "";
        for(int i=0; i<banned_id.size(); i++){ //user_id.size()에서 banned_id.size()만큼 골라서 순열 만들기
            if(!verify(user_id[i], banned_id[i])){
                flag = false;
                break;
            }
        }
        
        //해당 순열이 banned_id 후보에 적합하다면
        if(flag){
            //해당 순열을 정렬해야함. - [frodo, frodoc], [frodoc, frodo]는 같게 취급해야함.
            vector<string> temp; 
            for(int i=0; i<banned_id.size(); i++){
                temp.push_back(user_id[i]);
            }
            
            sort(temp.begin(), temp.end());
            
            //문자열 하나로 다 합쳐서 set에 넣어 중복 제거
            for(int i=0; i<banned_id.size(); i++){
                allId += temp[i];
            }
            
            idSet.insert(allId);
        }
    }
    while(next_permutation(user_id.begin(), user_id.end()));
    
    answer = idSet.size();
    
    return answer;
}