#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

//map, stringstream
//map - key: uid, value: 이름
//stringstream - 공백 기준으로 파싱
vector<string> solution(vector<string> record) {
    vector<string> answer, words;
    vector<vector<string>> recordWords(record.size());
    map<string, string> uidAndName;
    
    for(int i=0; i<record.size(); i++){
        
        stringstream ss(record[i]);
        string token;
        
        while(getline(ss, token, ' ')){
            words.push_back(token);
        }
        
        if(words[0]=="Enter" || words[0]=="Change"){
            uidAndName[words[1]] = words[2];
        }
        
        recordWords[i].push_back(words[0]);
        recordWords[i].push_back(words[1]);
        
        words.clear();
    }
    
    //Enter, Leave일 때만 메시지 answer에 저장
    for(int i=0; i<recordWords.size(); i++){
        
        if(recordWords[i][0]=="Enter"){
            answer.push_back(uidAndName[recordWords[i][1]]+"님이 들어왔습니다.");
        }
        else if(recordWords[i][0]=="Leave"){
            answer.push_back(uidAndName[recordWords[i][1]]+"님이 나갔습니다.");
        }
    }
    
    return answer;
}