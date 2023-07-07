#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

//조건 처리
vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    set<string> beforeWords;
    char lastChar;
    
    answer.assign(2,0);
    
    //한 문자 단어 불가
    if(words[0].length()==1){
        answer[0] = 1;
        answer[1] = 1;
        return answer;
    }
    
    beforeWords.insert(words[0]);
    lastChar = words[0][words[0].length()-1];
    
    for(int i=1; i<words.size(); i++){
        
        //중복 단어 불가, 이전 단어의 마지막 문자로 시작하지 않는 경우 불가
        if(beforeWords.find(words[i])!=beforeWords.end() || words[i][0]!=lastChar){
            answer[0] = i%n+1;
            answer[1] = i/n+1;
            break;
        }
        else{
            beforeWords.insert(words[i]);
            lastChar = words[i][words[i].length()-1];
        }
    }

    return answer;
}